#include "fichier.h"

int main() {
    int mon_choix = -1;
    // j'ai stocké le mdp ici pour éviter les variable globale
    char mot_de_passe_actuel[TAILLE] = "tekien2026";

    while (mon_choix != 0) {
        montrer_le_menu();
        printf("Votre choix : ");
        scanf("%d", &mon_choix);

        if (mon_choix == 1) {
            mode_enseignant(mot_de_passe_actuel);
        } else if (mon_choix == 2) {
            mode_etudiant();
        } else if (mon_choix == 0) {
            printf(JAUNE "Fin du programme. Au revoir ! %s\n" RESET, ETOILE);
        } else {
            printf(ROUGE "Erreur : Ce choix n'existe pas.\n" RESET);
            
            // On ajoute aussi la pause ici pour que l'utilisateur voit l'erreur
            printf("\nAppuyez sur Entrée pour continuer...");
            getchar(); getchar();
        }
    }
    return 0;
}