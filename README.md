Questions pour un Tekien — Projet QCM
Application de gestion de QCM en langage C (préING1 — CY Tech 2025-2026)
Auteurs : Najm-Eddine ASABBAN, Sekou SOUMAH
Cette application permet aux enseignants de créer et gérer des QCM, et aux étudiants de les
passer et d'obtenir leur note automatiquement.
Prérequis
Un compilateur C (type gcc).
Un terminal (Linux, macOS ou WSL sous Windows).
Compilation
make — compile et lance le programme
make clean — supprime les fichiers objets (.o)
make mrproper — supprime les fichiers objets et l'exécutable
Lancement manuel
./qcm_tekien
Utilisation
Au démarrage, un menu propose deux modes :
• Mode enseignant (1) — protégé par mot de passe (tekien par défaut). Permet de créer de
nouveaux QCM sauvegardés dans des fichiers.
• Mode étudiant (2) — permet de passer les QCM disponibles et d'obtenir sa note sur 20.
• Quitter (0)
QCM disponibles
football — Divers — 10 questions — Points négatifs : Non — Mode séquentiel : Oui
languageC — Informatique — 10 questions — Points négatifs : Non — Mode séquentiel : Non
Calculs — Mathématique — 10 questions — Points négatifs : Oui — Mode séquentiel : Oui
