
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAILLE 100

// Couleurs et forme
#define ROUGE   "\033[31m"
#define VERT    "\033[32m"
#define JAUNE   "\033[33m"
#define BLEU    "\033[34m"
#define RESET   "\033[0m"

#define FLOCON  "\u2744"
#define COMETE   "\u2604"
#define ETOILE   "\u2728"

// Structure pour une seule question 
typedef struct {
    char texte_question[300];
    char choix[4][100];
    int solution;
} UneQuestion;

// Structure pour les réglages du QCM
typedef struct {
    char nom_du_qcm[TAILLE];
    int points_negatifs;   // 1 pour Oui(on enleve des points), 0 pour Non(on enleve rien) 
    int mode_sequentiel;   // 1 pour Obligatoire(oblige de repondre pour passer a la question suivante), 0 pour Libre(peut naviguer librement entre les questions)
} ReglagesQcm;

// appel de nos fonctions
void montrer_le_menu();
void mode_enseignant(char *mot_de_passe);
void changer_le_mot_de_passe(char *ancien_mot_de_passe);
void mode_etudiant();
void creer_qcm();