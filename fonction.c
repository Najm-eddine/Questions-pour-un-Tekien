#include "fichier.h"

void montrer_le_menu() {
    system("clear"); // efface ce qu'il y avaios sur le terminal
    
    printf(BLEU "╔════════════════════════════════════╗\n" RESET); // le reset sert a reset la couleurs pour qu'elle reste pas bleu ici par exemple
    printf(BLEU "║" RESET JAUNE "   %s  QUESTIONS POUR UN TEKIEN  %s   " RESET BLEU "║\n" RESET, ETOILE, ETOILE);
    printf(BLEU "╚════════════════════════════════════╝\n\n" RESET);
    
    // choix du mode 
    printf(VERT "  %s 1." RESET " Mode Enseignant\n", CARRE);
    printf(VERT "  %s 2." RESET " Mode Etudiant\n", CARRE);
    printf(ROUGE "  %s 0." RESET " Quitter\n\n", CARRE);
}

void changer_le_mot_de_passe(char *mot_de_passe) {
    char nouveau[TAILLE];
    printf(JAUNE "Entrez le nouveau mot de passe : " RESET);
    scanf("%s", nouveau);
    
    strcpy(mot_de_passe, nouveau); // on remplace l'ancien mot de passe par le nouveau
    printf(VERT "Succès : Mot de passe modifié %s\n" RESET, COEUR);
    
    printf("\nAppuyez sur Entrée pour continuer...");
    getchar(); getchar(); //fait une pause pour pas que l'ecran s'efface direct a cause du systeme clear
}

void mode_enseignant(char *mot_de_passe) {
    char essai[TAILLE];
    int choix_prof = -1;

    printf(JAUNE "Mot de passe requis : " RESET);
    scanf("%s", essai);

    // verification du mdp
    if (strcmp(essai, mot_de_passe) == 0) {
        while (choix_prof != 0) {

            system("clear"); //On nettoie l'écran à chaque tour

            printf("\n" BLEU "--- %s ESPACE ENSEIGNANT %s ---" RESET "\n", ETOILE, ETOILE);
            printf("1. Creer un QCM (bientot disponible)\n");
            printf("2. Modifier le mot de passe\n");
            printf(ROUGE "0. Retour" RESET "\n");
            printf("Choix : ");
            
            //securite pour verifier que l'utilisateur a bien envoyé un nombre
            // 1.On vérifie si scanf a bien réussi à lire 1 seul nombre
            if (scanf("%d", &choix_prof) != 1) {
                // Si c'est une lettre ou un symbole on met erreur
                while(getchar() != '\n'); 
                printf(ROUGE "Erreur : Vous devez entrer un nombre !\n" RESET);
                printf("\nAppuyez sur Entrée pour continuer...");
                getchar();
                choix_prof = -1; // on securise pour eviter que l'ordi garde l'ancien chiffre en memoire
                continue; // On skip la suite et on remonte au début du while
            }

            // 2. si on a bien un nombre on verifie on a lequel
            if (choix_prof == 1) {
                printf("Ici, on pourra bientot enregistrer des fichiers !\n");
                printf("\nAppuyez sur Entrée pour continuer...");
                getchar(); getchar();
            } else if (choix_prof == 2) {
                changer_le_mot_de_passe(mot_de_passe);
            } else if (choix_prof != 0) {
                // Si c'est un nombre mais pas 0, 1, ni 2
                printf(ROUGE "Erreur : Ce choix n'existe pas. %s\n" RESET, CARRE);
                printf("\nAppuyez sur Entrée pour continuer...");
                getchar(); getchar();
            }
            // fin de la partie securité
        }
    } else {
        printf(ROUGE "Acces refuse ! %s\n" RESET, CARRE);
        printf("\nAppuyez sur Entrée pour revenir au menu...");
        getchar(); getchar(); 
    }
}

void mode_etudiant() {
    system("clear");
    printf(VERT "Bienvenue etudiant %s" RESET " Choisissez un QCM dans la liste...\n", COEUR);
    /* On chargera les fichiers ici plus tard */
    
    printf("\nAppuyez sur Entrée pour revenir au menu...");
    getchar(); getchar();
}