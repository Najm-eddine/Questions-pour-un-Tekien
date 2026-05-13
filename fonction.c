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
    printf(JAUNE "Nom du QCM (ex: Info) : " RESET);
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
        

        //sert à créer les choix de reponses que l'étudiant verra
        for (int j = 0; j < 4; j++) { // on répète 4 fois car 4 reponses max
            printf("  Réponse %d : ", j + 1);
            fgets(q.choix[j], 100, stdin);
          
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
        fprintf(fichier, "%s", q.texte_question);
        for(int j = 0; j < 4; j++) {
            fprintf(fichier, "%s", q.choix[j]);
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
    char nom_qcm[TAILLE];
    char nom_fichier[TAILLE + 4];
    FILE *fichier;
    ReglagesQcm reglages;
    int nb_questions;
    float score = 0;

    system("clear");
    printf(VERT "--- %s BIENVENUE ESPACE ÉTUDIANT %s ---" RESET "\n\n", FLOCON, FLOCON);
    
    printf(JAUNE "Entrez le nom du QCM à passer  : " RESET);
    scanf("%s", nom_qcm);
    sprintf(nom_fichier, "%s.txt", nom_qcm);

    fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf(ROUGE "Erreur : Le QCM '%s' n'existe pas.\n" RESET, nom_qcm);
        printf("\nAppuyez sur Entrée pour revenir au menu...");
        while(getchar() != '\n'); getchar(); //ca sert a ignore toute les lettre tapées par erreur jusqu'au prochain appuie de la touche entrée
        return;
    }

    //  On lit les réglages au début du fichier 
    fscanf(fichier, "%d", &reglages.points_negatifs);
    fscanf(fichier, "%d", &reglages.mode_sequentiel);
    fscanf(fichier, "%d", &nb_questions); //nb question va nous servire a l'allocation dynamique

    //  On crée le tableau de la taille exacte du nombre de questions
    UneQuestion *liste = malloc(nb_questions *sizeof(UneQuestion));
    if (liste == NULL) {
        printf(ROUGE "Impossible de charger les questions.\n" RESET);
        fclose(fichier);
        return;
    }

    // remplissage du tableau avec les donné du fichier
    for (int i = 0; i < nb_questions; i++) {
        fgetc(fichier); // supprime le \n qui est derrier eles chiffres afin de ne pas créer de décalage car fgets s'arrête dès qu'il rencontre un \n donc il le saute 
        
        fgets(liste[i].texte_question, 300, fichier);
        

        for (int j = 0; j < 4; j++) {
            fgets(liste[i].choix[j], 100, fichier);
            
        }
        fscanf(fichier, "%d", &liste[i].solution);
    }
    fclose(fichier); 

    //  On pose les questions à l'étudiant
    float points_par_question = 20.0 / nb_questions; // note sur 20

    for (int i = 0; i < nb_questions; i++) {
        int reponse_eleve = -1;
        system("clear");
        printf(BLEU "Question %d / %d : %s" RESET "\n\n", i + 1, nb_questions, liste[i].texte_question);
        
        for (int j = 0; j < 4; j++) {
            printf("  %d. %s\n", j + 1, liste[i].choix[j]);
        }

        printf(JAUNE "\nVotre réponse (1-4) : " RESET);
        while (scanf("%d", &reponse_eleve) != 1 || reponse_eleve < 1 || reponse_eleve > 4) {
            while(getchar() != '\n');
            printf(ROUGE "Erreur : Choisissez entre 1 et 4 !\n" RESET);
            printf(JAUNE "Votre réponse (1-4) : " RESET);
        }

        if (reponse_eleve == liste[i].solution) {
            printf(VERT "\nBonne réponse ! %s\n" RESET, ETOILE);
            score += points_par_question;
        } else {
            printf(ROUGE "\nMauvaise réponse... %s\n" RESET, COMETE);
            if (reglages.points_negatifs == 1) {
                score -= (points_par_question / 2); //on enleve la moitié des poins de la questions si la reponses est fausse
            }
        }
        
        printf("\nAppuyez sur Entrée pour la suite...");
        while(getchar() != '\n'); getchar(); //ca sert a ignore toute les lettre tapées par erreur jusqu'au prochain appuie de la touche entrée
    }

    
    system("clear");
    if (score < 0){
        score = 0;
    } // On ne donne pas de note en dessous de zéro
    
    printf(JAUNE "╔════════════════════════════════════╗\n" RESET);
    printf(JAUNE "║          RÉSULTAT DU QCM           ║\n" RESET);
    printf(JAUNE "╚════════════════════════════════════╝\n\n" RESET);
    printf("  QCM : %s\n", nom_qcm);
    printf("  Note finale : " VERT "%.2f / 20" RESET "\n\n", score);

    
    free(liste); 

    printf("Appuyez sur Entrée pour revenir au menu...");
    getchar();
}