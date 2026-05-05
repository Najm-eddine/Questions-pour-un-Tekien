#include "fichier.h"

void montrer_le_menu() {
    system("clear"); // efface ce qu'il y avait sur le terminal
    
    printf(BLEU "╔══════════════════════════════════╗\n" RESET); 
    printf(BLEU "║" RESET JAUNE " %s  QUESTIONS POUR UN TEKIEN  %s " RESET BLEU "║\n" RESET, ETOILE, ETOILE);
    printf(BLEU "╚══════════════════════════════════╝\n\n" RESET);
    
    // choix du mode 
    printf(VERT "  %s 1." RESET " Mode Enseignant\n", COMETE);
    printf(VERT "  %s 2." RESET " Mode Etudiant\n", COMETE);
    printf(ROUGE "  %s 0." RESET " Quitter\n\n", COMETE);
}

void changer_le_mot_de_passe(char *mot_de_passe) {
    char nouveau[TAILLE];
    printf(JAUNE "Entrez le nouveau mot de passe : " RESET);
    scanf("%s", nouveau);
    
    strcpy(mot_de_passe, nouveau); // on remplace l'ancien mot de passe par le nouveau
    printf(VERT "Succès : Mot de passe modifié %s\n" RESET, FLOCON);
    
    printf("\nAppuyez sur Entrée pour continuer...");
    getchar(); getchar(); // Met le programme en pause pour laisser le temps de lire avant que le systeme clear face effet
}

void creer_qcm() {
    ReglagesQcm mon_qcm;
    UneQuestion q;
    int nb_questions;
    FILE *fichier; 
    char nom_fichier[TAILLE + 4]; // le + 4 c'est pour le .txt qu'on rajoute apres le nom du fichier

    system("clear");
    printf(BLEU "--- %s CRÉATION D'UN NOUVEAU QCM %s ---" RESET "\n\n", ETOILE, ETOILE);

    //  Réglage du QCM
    printf(JAUNE "Nom du QCM (sans espaces, ex: Histoire) : " RESET);
    scanf("%s", mon_qcm.nom_du_qcm);
    
    sprintf(nom_fichier, "%s.txt", mon_qcm.nom_du_qcm); // on change le nom du fichier 

    // Sécurité Points Négatifs avec Clear
    printf(JAUNE "Points négatifs ? (1: Oui / 0: Non) : " RESET);
    while (scanf("%d", &mon_qcm.points_negatifs) != 1 || (mon_qcm.points_negatifs != 0 && mon_qcm.points_negatifs != 1)) { // scanf("%d", .....) renvoie 1 si c'est bien un nombre
        while(getchar() != '\n'); 
        system("clear"); // On efface la pile d'erreurs
        printf(ROUGE "Erreur : Tapez 0 ou 1 uniquement !\n" RESET);
        printf(JAUNE "Points négatifs ? (1: Oui / 0: Non) : " RESET);
    }

    // Sécurité Mode Séquentiel avec Clear
    printf(JAUNE "Mode séquentiel ? (1: Oui / 0: Non) : " RESET);
    while (scanf("%d", &mon_qcm.mode_sequentiel) != 1 || (mon_qcm.mode_sequentiel != 0 && mon_qcm.mode_sequentiel != 1)) { // scanf("%d", .....) renvoie 1 si c'est bien un nombre
        while(getchar() != '\n');
        system("clear"); // On efface la pile d'erreurs
        printf(ROUGE "Erreur : Tapez 0 ou 1 uniquement !\n" RESET);
        printf(JAUNE "Mode séquentiel ? (1: Oui / 0: Non) : " RESET);
    }

    // Sécurité Nombre de Questions avec Clear
    printf(JAUNE "Combien de questions voulez-vous créer ? : " RESET);
    while (scanf("%d", &nb_questions) != 1 || nb_questions <= 0) { // scanf("%d", .....) renvoie 1 si c'est bien un nombre
        while(getchar() != '\n');
        system("clear"); // On efface la pile d'erreurs
        printf(ROUGE "Erreur : Entrez un nombre entier supérieur à 0 !\n" RESET);
        printf(JAUNE "Combien de questions voulez-vous créer ? : " RESET);
    }

    //  Ouverture du fichier
    fichier = fopen(nom_fichier, "w");

    if (fichier == NULL) {
        printf(ROUGE "Erreur fopen : Impossible de créer le fichier.\n" RESET);
        printf("\nAppuyez sur Entrée pour revenir au menu...");
        while(getchar() != '\n'); getchar(); //ca sert a ignore toute les lettre tapées par erreur jusqu'au prochain appuie de la touche entrée
        return;
    }

    // on ecrit les infos dans le fichier pour pouvoir les traiter plus tard
    fprintf(fichier, "%d\n", mon_qcm.points_negatifs);
    fprintf(fichier, "%d\n", mon_qcm.mode_sequentiel);
    fprintf(fichier, "%d\n", nb_questions);
     

    for (int i = 0; i < nb_questions; i++) {
        system("clear");
        printf(VERT "--- Question n°%d / %d ---" RESET "\n", i + 1, nb_questions);
        
        printf("Texte de la question : ");
        while(getchar() != '\n'); // ca sert a ignore toute les lettre tapées par erreur jusqu'au prochain appuie de la touche entrée
        fgets(q.texte_question, 300, stdin); // lit depuis la question depuis  clavier(stdin) car le fichier vient d'être créé en écriture ("w") et il est encore vide
        q.texte_question[strcspn(q.texte_question, "\n")] = 0; // Nettoie la phrase en remplaçant le retour à la ligne a la fin par  par un caractère de fin de chaîne (\0)

        //sert à créer les choix de reponses que l'étudiant verra
        for (int j = 0; j < 4; j++) { // on répète 4 fois car 4 reponses max
            printf("  Réponse %d : ", j + 1);
            fgets(q.choix[j], 100, stdin);
            q.choix[j][strcspn(q.choix[j], "\n")] = 0;
        }

        // Sécurité Solution
        printf(JAUNE "Numéro de la bonne réponse (1 à 4) : " RESET);
        while (scanf("%d", &q.solution) != 1 || q.solution < 1 || q.solution > 4) {
            while(getchar() != '\n');
            system("clear"); // On nettoie
            printf(VERT "--- Question n°%d / %d ---" RESET "\n", i + 1, nb_questions);
            printf("Question : %s\n", q.texte_question);
            for(int k=0; k<4; k++) printf("  %d. %s\n", k+1, q.choix[k]);
            printf(ROUGE "\nErreur : Choisissez un chiffre entre 1 et 4 !\n" RESET);
            printf(JAUNE "Numéro de la bonne réponse (1 à 4) : " RESET);
        }

        // Enfin, on affiche dans le fichier la question , les differentes possibilités et la solution
        fprintf(fichier, "%s\n", q.texte_question);
        for(int j = 0; j < 4; j++) {
            fprintf(fichier, "%s\n", q.choix[j]);
        }
        fprintf(fichier, "%d\n", q.solution);
    }

    fclose(fichier); 
    printf(VERT "\n%s Succès : Le fichier '%s' a été enregistré ! %s" RESET "\n", FLOCON, nom_fichier, FLOCON);

    printf("\nAppuyez sur Entrée pour continuer...");
    while(getchar() != '\n'); getchar(); //ca sert a ignore toute les lettre tapées par erreur jusqu'au prochain appuie de la touche entrée
}

void mode_enseignant(char *mot_de_passe) {
    char essai[TAILLE];
    int choix_prof = -1;

    printf(JAUNE "Mot de passe requis : " RESET);
    scanf("%s", essai);

    if (strcmp(essai, mot_de_passe) == 0) {
        while (choix_prof != 0) {
            system("clear");
            printf("\n" BLEU "--- %s ESPACE ENSEIGNANT %s ---" RESET "\n", ETOILE, ETOILE);
            printf("1. Creer un QCM\n");
            printf("2. Modifier le mot de passe\n");
            printf(ROUGE "0. Retour" RESET "\n");
            printf("Choix : ");
            
            if (scanf("%d", &choix_prof) != 1) {
                while(getchar() != '\n'); 
                printf(ROUGE "Erreur : Entrez un nombre !\n" RESET);
                getchar();
                choix_prof = -1;
                continue;
            }

            if (choix_prof == 1) {
                creer_qcm(); 
            } else if (choix_prof == 2) {
                changer_le_mot_de_passe(mot_de_passe);
                printf(JAUNE "\nDéconnexion automatique pour sécurité..." RESET "\n");
                printf("Appuyez sur Entrée pour vous reconnecter...");
                getchar(); 
                choix_prof = 0; 
            } else if (choix_prof != 0) {
                printf(ROUGE "Erreur : Ce choix n'existe pas.\n" RESET);
                printf("\nAppuyez sur Entrée...");
                getchar(); getchar(); // Met le programme en pause pour laisser le temps de lire avant que le systeme clear face effet
            }
        }
    } else {
        printf(ROUGE "Acces refuse ! %s\n" RESET, COMETE);
        printf("\nAppuyez sur Entrée pour revenir au menu...");
        getchar(); getchar(); // Met le programme en pause pour laisser le temps de lire avant que le systeme clear face effet
    }
}

void mode_etudiant() {
    system("clear");
    printf(VERT "Bienvenue etudiant %s" RESET " Choisissez un QCM dans la liste...\n", FLOCON);
    /* La lecture des fichiers sera la prochaine étape */
    
    printf("\nAppuyez sur Entrée pour revenir au menu...");
    getchar(); getchar();
}