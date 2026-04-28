#include "fichier.h"

void montrer_le_menu() {
    system("clear"); // efface ce qu'il y avaios sur le terminal
    
    printf(BLEU "╔════════════════════════════════════╗\n" RESET);
    printf(BLEU "║" RESET JAUNE "   %s  QUESTIONS POUR UN TEKIEN  %s   " RESET BLEU "║\n" RESET, ETOILE, ETOILE);
    printf(BLEU "╚════════════════════════════════════╝\n\n" RESET);
    
    printf(VERT "  %s 1." RESET " Mode Enseignant\n", CARRE);
    printf(VERT "  %s 2." RESET " Mode Etudiant\n", CARRE);
    printf(ROUGE "  %s 0." RESET " Quitter\n\n", CARRE);
}

void changer_le_mot_de_passe(char *mot_de_passe) {
    char nouveau[TAILLE];
    printf(JAUNE "Entrez le nouveau mot de passe : " RESET);
    scanf("%s", nouveau);
    
    /* On remplace l'ancien par le nouveau */
    strcpy(mot_de_passe, nouveau);
    printf(VERT "Succès : Mot de passe modifié %s\n" RESET, COEUR);
    
    printf("\nAppuyez sur Entrée pour continuer...");
    getchar(); getchar(); 
}

void mode_enseignant(char *mot_de_passe) {
    char essai[TAILLE];
    int choix_prof = -1;

    printf(JAUNE "Mot de passe requis : " RESET);
    scanf("%s", essai);

    /* On vérifie si c'est le bon */
    if (strcmp(essai, mot_de_passe) == 0) {
        while (choix_prof != 0) {
            printf("\n" BLEU "--- %s ESPACE ENSEIGNANT %s ---" RESET "\n", ETOILE, ETOILE);
            printf("1. Creer un QCM (bientot disponible)\n");
            printf("2. Modifier le mot de passe\n");
            printf(ROUGE "0. Retour" RESET "\n");
            printf("Choix : ");
            scanf("%d", &choix_prof);

            if (choix_prof == 1) {
                printf("Ici, on pourra bientot enregistrer des fichiers !\n");
                printf("\nAppuyez sur Entrée pour continuer...");
                getchar(); getchar();
            } else if (choix_prof == 2) {
                changer_le_mot_de_passe(mot_de_passe);
            }
        }
    } else {
        printf(ROUGE "Acces refuse ! %s\n" RESET, CARRE);
        printf("\nAppuyez sur Entrée pour revenir au menu...");
        getchar(); getchar(); 
    }
}

void mode_etudiant() {
    printf(VERT "Bienvenue etudiant %s" RESET " Choisissez un QCM dans la liste...\n", COEUR);
    /* On chargera les fichiers ici plus tard */
    
    printf("\nAppuyez sur Entrée pour revenir au menu...");
    getchar(); getchar();
}