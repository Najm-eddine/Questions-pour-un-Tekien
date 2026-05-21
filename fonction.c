#include "fichier.h"

// Affiche le menu principal avec une interface graphique en ASCII et des codes couleurs
void montrer_le_menu() {
    system("clear"); 
    
    printf(BLEU "╔═══════════════════════════════════════════════╗\n" RESET); 
    printf(BLEU "║ " RESET JAUNE "            %s  MENU PRINCIPAL  %s           " RESET BLEU " ║\n" RESET, ETOILE, ETOILE);
    printf(BLEU "╠═══════════════════════════════════════════════╣\n" RESET); 
    printf(BLEU "║ " JAUNE "  ___                  _   _                 " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE " / _ \\ _   _  ___  ___| |_(_) ___  _ __  ___ " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "| | | | | | |/ _ \\/ __| __| |/ _ \\| '_ \\/ __|" BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "| |_| | |_| |  __/\\__ \\ |_| | (_) | | | \\__ \\" BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE " \\__\\_\\__,_|\\___||___/\\__|_|\\___/|_| |_|___/ " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "            |  _ \\ ___  _   _ _ __           " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "            | |_) / _ \\| | | | '__|          " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "            |  __/ (_) | |_| | |             " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "   _   _    |_|  _\\___/ \\__,_|_|             " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "  | | | |_ __   |_   _|__| | _(_) ___ _ __   " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "  | | | | '_ \\    | |/ _ \\ |/ / |/ _ \\ '_ \\  " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "  | |_| | | | |   | |  __/   <| |  __/ | | | " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "   \\___/|_| |_|   |_|\\___|_|\\_\\_|\\___|_| |_| " BLEU " ║\n" RESET);
    printf(BLEU "╚═══════════════════════════════════════════════╝\n\n" RESET);
    
    printf(VERT "  %s 1." RESET " Mode Enseignant\n", COMETE);
    printf(VERT "  %s 2." RESET " Mode Etudiant\n", COMETE);
    printf(ROUGE "  %s 0." RESET " Quitter\n\n", COMETE);
}

// Remplace l'ancien mot de passe par le nouveau en utilisant la fonction strcpy().
void changer_le_mot_de_passe(char *mot_de_passe) {
    char nouveau[TAILLE];
    printf(JAUNE "Entrez le nouveau mot de passe : " RESET);
    scanf("%s", nouveau);
    
    strcpy(mot_de_passe, nouveau);
    printf(VERT "Succès : Mot de passe modifié %s\n" RESET, FLOCON);
    
    printf("\nAppuyez sur Entrée pour continuer...");
    getchar(); getchar();
}

// Fonction principale de création de QCM
void creer_qcm() {
    ReglagesQcm mon_qcm;
    UneQuestion q;
    int nb_questions;
    FILE *fichier; 
    char nom_fichier[TAILLE + 4];

    system("clear");
    printf(BLEU "--- %s CRÉATION D'UN NOUVEAU QCM %s ---" RESET "\n\n", ETOILE, ETOILE);

    //  Réglage du QCM
    printf(JAUNE "Nom du QCM (ex: Calculs) : " RESET);
    scanf("%s", mon_qcm.nom_du_qcm);
    
    sprintf(nom_fichier, "%s.txt", mon_qcm.nom_du_qcm);

    // choix de la catégorie
    int choix_cat = -1;
    printf(JAUNE "\nDans quelle catégorie classer ce QCM ?\n" RESET);
    printf("  1. Informatique\n");
    printf("  2. Mathématiques\n");
    printf("  3. Divers\n");
    printf(JAUNE "\nVotre choix (1-3) : " RESET);
    while (scanf("%d", &choix_cat) != 1 || choix_cat < 1 || choix_cat > 3) {
        while(getchar() != '\n');
        printf(ROUGE "Erreur : Choisissez un nombre entre 1 et 3 !\n" RESET);
        printf(JAUNE "Votre choix (1-3) : " RESET);
    }
    while(getchar() != '\n');

    // Sécurité Points Négatifs avec Clear
    printf(JAUNE "Points négatifs ? (1: Oui / 0: Non) : " RESET);
    while (scanf("%d", &mon_qcm.points_negatifs) != 1 || (mon_qcm.points_negatifs != 0 && mon_qcm.points_negatifs != 1)) { 
        while(getchar() != '\n'); 
        system("clear");
        printf(ROUGE "Erreur : Tapez 0 ou 1 uniquement !\n" RESET);
        printf(JAUNE "Points négatifs ? (1: Oui / 0: Non) : " RESET);
    }

    // Sécurité Mode Séquentiel avec Clear
    printf(JAUNE "Mode séquentiel ? (1: Oui / 0: Non) : " RESET);
    while (scanf("%d", &mon_qcm.mode_sequentiel) != 1 || (mon_qcm.mode_sequentiel != 0 && mon_qcm.mode_sequentiel != 1)) {
        while(getchar() != '\n');
        system("clear"); 
        printf(ROUGE "Erreur : Tapez 0 ou 1 uniquement !\n" RESET);
        printf(JAUNE "Mode séquentiel ? (1: Oui / 0: Non) : " RESET);
    }

    // Sécurité Nombre de Questions avec Clear
    printf(JAUNE "Combien de questions voulez-vous créer ? : " RESET);
    while (scanf("%d", &nb_questions) != 1 || nb_questions <= 0) {
        while(getchar() != '\n');
        system("clear"); 
        printf(ROUGE "Erreur : Entrez un nombre entier supérieur à 0 !\n" RESET);
        printf(JAUNE "Combien de questions voulez-vous créer ? : " RESET);
    }

    
    fichier = fopen(nom_fichier, "w");

    if (fichier == NULL) {
        printf(ROUGE "Erreur fopen : Impossible de créer le fichier.\n" RESET);
        printf("\nAppuyez sur Entrée pour revenir au menu...");
        while(getchar() != '\n'); getchar();
        return;
    }
    
    // Ajoute le QCM dans le fichier correspondant à sa catégorie
    FILE *f_cat = NULL;
    if (choix_cat == 1) {
        f_cat = fopen("cat_informatique.txt", "a");
    } 
    else if (choix_cat == 2) {
        f_cat = fopen("cat_mathematique.txt", "a");
    } 
    else if (choix_cat == 3) {
        f_cat = fopen("cat_divers.txt", "a");
    }

    if (f_cat != NULL) {
        fprintf(f_cat, "%s\n", mon_qcm.nom_du_qcm);
        fclose(f_cat);
    }

    // on ecrit les infos dans le fichier pour pouvoir les traiter plus tard
    fprintf(fichier, "%d\n", mon_qcm.points_negatifs);
    fprintf(fichier, "%d\n", mon_qcm.mode_sequentiel);
    fprintf(fichier, "%d\n", nb_questions);
     
    // Efface la touche 'Entrée' restée en mémoire, puis lit toute la phrase avec ses espaces
    for (int i = 0; i < nb_questions; i++) {
        system("clear");
        printf(VERT "--- Question n°%d / %d ---" RESET "\n", i + 1, nb_questions);
        
        printf("Texte de la question : ");
        while(getchar() != '\n'); 
        fgets(q.texte_question, 300, stdin);
        

        // Boucle 4 fois pour demander et enregistrer les 4 propositions de réponse
        for (int j = 0; j < 4; j++) { 
            printf("  Réponse %d : ", j + 1);
            fgets(q.choix[j], 100, stdin);
          
        }

        // Sécurité réponse
        // Si erreur, on vide la mémoire, on nettoie l'écran et on réaffiche proprement la question.
        printf(JAUNE "Numéro de la bonne réponse (1 à 4) : " RESET);
        while (scanf("%d", &q.solution) != 1 || q.solution < 1 || q.solution > 4) {
            while(getchar() != '\n');
            system("clear"); // On nettoie
            printf(VERT "--- Question n°%d / %d ---" RESET "\n", i + 1, nb_questions);
            printf("Question : %s\n", q.texte_question);
            for(int k=0; k<4; k++){ 
                printf("  %d. %s\n", k+1, q.choix[k]);
            }
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
    while(getchar() != '\n'); getchar();
}

// Fonction principale de création de QCM
void mode_enseignant(char *mot_de_passe) {
    char essai[TAILLE];
    int choix_prof = -1;

    // Vérifie si le mot de passe est correct avec strcmp()
    printf(JAUNE "Mot de passe requis : " RESET);
    scanf("%s", essai);
    if (strcmp(essai, mot_de_passe) == 0) {
        while (choix_prof != 0) {
            system("clear");
            printf(BLEU "╔══════════════════════════════════════════════════════════════╗\n" RESET);
            printf(BLEU "║ " JAUNE " _____ ____  ____   _    ____ _____                         " BLEU " ║\n" RESET);
            printf(BLEU "║ " JAUNE "| ____/ ___||  _ \\ / \\  / ___| ____|                        " BLEU " ║\n" RESET);
            printf(BLEU "║ " JAUNE "|  _| \\___ \\| |_) / _ \\| |   |  _|                          " BLEU " ║\n" RESET);
            printf(BLEU "║ " JAUNE "| |___ ___) |  __/ ___ \\ |___| |___                         " BLEU " ║\n" RESET);
            printf(BLEU "║ " JAUNE "|_____|____/|_|_/_/___\\_\\____|_____|  _    _    _   _ _____ " BLEU " ║\n" RESET);
            printf(BLEU "║ " JAUNE "| ____| \\ | / ___|| ____|_ _/ ___| \\ | |  / \\  | \\ | |_   _|" BLEU " ║\n" RESET);
            printf(BLEU "║ " JAUNE "|  _| |  \\| \\___ \\|  _|  | | |  _|  \\| | / _ \\ |  \\| | | |  " BLEU " ║\n" RESET);
            printf(BLEU "║ " JAUNE "| |___| |\\  |___) | |___ | | |_| | |\\  |/ ___ \\| |\\  | | |  " BLEU " ║\n" RESET);
            printf(BLEU "║ " JAUNE "|_____|_| \\_|____/|_____|___\\____|_| \\_/_/   \\_\\_| \\_| |_|  " BLEU " ║\n" RESET);
            printf(BLEU "╚══════════════════════════════════════════════════════════════╝\n\n" RESET);
            printf("1. Creer un QCM\n");
            printf("2. Modifier le mot de passe\n");
            printf(ROUGE "0. Retour" RESET "\n");
            printf("Choix : ");
            
            // sécurité choix du professeur
            if (scanf("%d", &choix_prof) != 1) {
                while(getchar() != '\n'); 
                printf(ROUGE "Erreur : Entrez un nombre !\n" RESET);
                getchar();
                choix_prof = -1;
                continue;
            }

            // Redirige vers la bonne action : créer un QCM (1) ou changer le mot de passe avec une déconnexion (2)
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
                getchar(); getchar();
            }
        }
    // Si le mot de passe est faux, refuse l'accès et met en pause avant de revenir au menu.    
    } else {
        printf(ROUGE "Acces refuse ! %s\n" RESET, COMETE);
        printf("\nAppuyez sur Entrée pour revenir au menu...");
        getchar(); getchar();
    }
}

// Fonction principale du mode étudiant
void mode_etudiant() {
    char nom_qcm[TAILLE];
    char nom_fichier[TAILLE + 4];
    FILE *fichier;
    ReglagesQcm reglages;
    int nb_questions;
    float note= 0;

    system("clear");
    printf(BLEU "╔══════════════════════════════════════════════════╗\n" RESET);
    printf(BLEU "║ " JAUNE " _____ ____  ____   _    ____ _____             " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "| ____/ ___||  _ \\ / \\  / ___| ____|            " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "|  _| \\___ \\| |_) / _ \\| |   |  _|              " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "| |___ ___) |  __/ ___ \\ |___| |___             " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "|_____|____/|_| /_/___\\_\\____|_____|_   _ _____ " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "| ____|_   _| | | |  _ \\_ _|  / \\  | \\ | |_   _|" BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "|  _|   | | | | | | | | | |  / _ \\ |  \\| | | |  " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "| |___  | | | |_| | |_| | | / ___ \\| |\\  | | |  " BLEU " ║\n" RESET);
    printf(BLEU "║ " JAUNE "|_____| |_|  \\___/|____/___/_/   \\_\\_| \\_| |_|  " BLEU " ║\n" RESET);
    printf(BLEU "╚══════════════════════════════════════════════════╝\n\n" RESET);

    // Sécurité de la saisie et vide le clavier en cas d'erreur
    int choix_cat = -1;
    printf(JAUNE "Choisissez une catégorie pour voir les QCM disponibles :\n" RESET);
    printf("  1. Informatique\n");
    printf("  2. Mathématiques\n");
    printf("  3. Divers\n");
    printf(JAUNE "\nVotre choix (1-3) : " RESET);
    
    while (scanf("%d", &choix_cat) != 1 || choix_cat < 1 || choix_cat > 3) {
        while(getchar() != '\n');
        printf(ROUGE "Erreur : Choisissez un nombre entre 1 et 3 !\n" RESET);
        printf(JAUNE "Votre choix (1-3) : " RESET);
    }
    while(getchar() != '\n');

    system("clear");
    printf(VERT "    %s QCM DISPONIBLES %s    " RESET "\n\n", ETOILE, ETOILE);
    
    // Ouvre le fichier de la catégorie choisie en mode lecture seule afin de consulter les QCM existants
    FILE *f_liste = NULL;
    if (choix_cat == 1) {
        f_liste = fopen("cat_informatique.txt", "r");
    }
    else if (choix_cat == 2) {
        f_liste = fopen("cat_mathematique.txt", "r");
    }
    else if (choix_cat == 3) {
        f_liste = fopen("cat_divers.txt", "r");
    }

    // On affiche la liste des QCM
    if (f_liste == NULL) {
        printf(ROUGE "Aucun QCM n'est encore enregistré dans cette catégorie.\n\n" RESET);
    } else {
        char nom_dispo[TAILLE];
        while (fgets(nom_dispo, sizeof(nom_dispo), f_liste)) {
            printf("  %s  %s", FLOCON, nom_dispo);
        }
        fclose(f_liste);
        printf("\n");
    }
    
    printf(JAUNE "Entrez le nom du QCM à passer  : " RESET);
    scanf("%s", nom_qcm);
    sprintf(nom_fichier, "%s.txt", nom_qcm);

    fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf(ROUGE "Erreur : Le QCM '%s' n'existe pas.\n" RESET, nom_qcm);
        printf("\nAppuyez sur Entrée pour revenir au menu...");
        while(getchar() != '\n'); getchar();
        return;
    }

    //  On lit les réglages au début du fichier 
    fscanf(fichier, "%d", &reglages.points_negatifs);
    fscanf(fichier, "%d", &reglages.mode_sequentiel);
    fscanf(fichier, "%d", &nb_questions);

    // On crée le tableau de la taille exacte du nombre de questions
    UneQuestion *liste = malloc(nb_questions *sizeof(UneQuestion));
    if (liste == NULL) {
        printf(ROUGE "Impossible de charger les questions.\n" RESET);
        fclose(fichier);
        return;
    }

    // Boucle pour lire chaque question l'une après l'autre :
    for (int i = 0; i < nb_questions; i++) {
        fgetc(fichier); // Avale le "\n" invisible laissé dans le fichier pour permettre au fgets juste apres de bien fonctionner
        
        fgets(liste[i].texte_question, 300, fichier);
        
        // Lit les 4 propositions de réponse l'une après l'autre, puis récupère le numero de la bonne réponse
        for (int j = 0; j < 4; j++) {
            fgets(liste[i].choix[j], 100, fichier);
            
        }
        fscanf(fichier, "%d", &liste[i].solution);
    }
    fclose(fichier); 

    float points_par_question = 20.0 / nb_questions; // note sur 20

    //  On pose les questions à l'étudiant
    for (int i = 0; i < nb_questions; i++) {
        int reponse_eleve = -1;
        system("clear");
        
        printf(BLEU "Question %d / %d : %s" RESET "\n\n", i + 1, nb_questions, liste[i].texte_question);

        printf(JAUNE "  [%.2f pt ]\n\n" RESET, points_par_question);
        
        // Affiche les 4 propositions de réponse numérotées de 1 à 4
        for (int j = 0; j < 4; j++) {
            printf("  %d. %s\n", j + 1, liste[i].choix[j]);
        }

        // Si le mode séquentiel est obligatoire (1), on force entre 1 et 4
        if (reglages.mode_sequentiel == 1) {
            printf(JAUNE "\nVotre réponse (1-4) : " RESET);
            while (scanf("%d", &reponse_eleve) != 1 || reponse_eleve < 1 || reponse_eleve > 4) {
                while(getchar() != '\n');
                printf(ROUGE "Erreur : Choisissez entre 1 et 4 !\n" RESET);
                printf(JAUNE "Votre réponse (1-4) : " RESET);
            }
        } 
        // Sinon, on ajoute le 0 pour pouvoir sauter la question
        else {
            printf(JAUNE "\nVotre réponse (0-4) (0 pour passer) : " RESET);
            while (scanf("%d", &reponse_eleve) != 1 || reponse_eleve < 0 || reponse_eleve > 4) {
                while(getchar() != '\n');
                printf(ROUGE "Erreur : Choisissez entre 0 et 4 !\n" RESET);
                printf(JAUNE "Votre réponse (0-4) (0 pour passer) : " RESET);
            }
        }

        // Si l'élève a tapé 0, on saute la question sans toucher a la note
        if (reponse_eleve == 0) {
            printf(JAUNE "\nQuestion sautée.\n" RESET);
        }
        else if (reponse_eleve == liste[i].solution) {
            printf(VERT "\nBonne réponse ! %s\n" RESET, ETOILE);
            note += points_par_question;
        } else {
            printf(ROUGE "\nMauvaise réponse... %s\n" RESET, COMETE);
            if (reglages.points_negatifs == 1) {
                note -= (points_par_question / 2);
            }
        }
        
        printf("\nAppuyez sur Entrée pour la suite...");
        while(getchar() != '\n'); getchar();
    }

    
    system("clear");
    if (note < 0){
        note = 0;
    } // On ne donne pas de note en dessous de zéro
    
    printf(BLEU "╔═══════════════════════════════════════════════════════════════════════════════╗\n" RESET);
    printf(BLEU "║ " JAUNE " ____  _____ ____  _   _ _   _____  _  _____    _____ ___ _   _    _    _   " BLEU "  ║\n" RESET);
    printf(BLEU "║ " JAUNE "|  _ \\| ____/ ___|| | | | | |_   _|/ \\|_   _|  |  ___|_ _| \\ | |  / \\  | |    " BLEU "║\n" RESET);
    printf(BLEU "║ " JAUNE "| |_) |  _| \\___ \\| | | | |   | | / _ \\ | |    | |_   | ||  \\| | / _ \\ | |    " BLEU "║\n" RESET);
    printf(BLEU "║ " JAUNE "|  _ <| |___ ___) | |_| | |___| |/ ___ \\| |    |  _|  | || |\\  |/ ___ \\| |___ " BLEU "║\n" RESET);
    printf(BLEU "║ " JAUNE "|_| \\_\\_____|____/ \\___/|_____|_/_/   \\_\\_|    |_|   |___|_| \\_/_/   \\_\\_____|"BLEU "║\n" RESET);
    printf(BLEU "╚═══════════════════════════════════════════════════════════════════════════════╝\n\n" RESET);
    printf("  QCM : %s\n", nom_qcm);
    printf("  Note finale : " VERT "%.2f / 20" RESET "\n\n", note);

    
    free(liste); 

    printf("Appuyez sur Entrée pour revenir au menu...");
    getchar();
}