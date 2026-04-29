#include "fichier.h"

int main() {
    int mon_choix = -1;
    // j'ai stocké le mdp ici pour éviter les variable globale
    char mot_de_passe_actuel[TAILLE] = "tekien2026";

    while (mon_choix != 0) {
        montrer_le_menu();
        printf("Votre choix : ");
        
        // securite pour verifier que l'utilisateur a bien envoyé un nombre
        if (scanf("%d", &mon_choix) != 1) { // scanf("%d", .....) renvoie 1 si c'est bien un nombre
            while(getchar() != '\n'); // tant qu'on a pas appuyer sur entrée
            printf(ROUGE "Erreur : Vous devez entrer un nombre !\n" RESET);
            printf("\nAppuyez sur Entrée pour continuer...");
            getchar();
            mon_choix = -1; // on securise pour eviter que l'ordi garde l'ancien chiffre en memoire
            continue; // remonte au debut du while
        }
        // fin de la securite

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