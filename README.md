# ❓ Questions pour un Tekien — Application de QCM en C

![Langage](https://img.shields.io/badge/langage-C-blue)
![Build](https://img.shields.io/badge/build-Makefile-green)
![École](https://img.shields.io/badge/CY%20Tech-préING1%202025--2026-orange)

Une application en terminal pour **créer, gérer et passer des QCM**. Les enseignants créent leurs questionnaires, et les étudiants les passent et reçoivent **automatiquement leur note sur 20**.

Projet réalisé en binôme dans le cadre du cycle préparatoire ingénieur à CY Tech.

**Auteurs :** Najm-Eddine ASABBAN, Sekou SOUMAH

---

## 🖥️ Aperçu

```
╔═══════════════════════════════════════════════╗
║             ✨  MENU PRINCIPAL  ✨            ║
╠═══════════════════════════════════════════════╣
║   ___                  _   _                  ║
║  / _ \ _   _  ___  ___| |_(_) ___  _ __  ___  ║
║ | | | | | | |/ _ \/ __| __| |/ _ \| '_ \/ __| ║
║ | |_| | |_| |  __/\__ \ |_| | (_) | | | \__ \ ║
║  \__\_\__,_|\___||___/\__|_|\___/|_| |_|___/  ║
║             |  _ \ ___  _   _ _ __            ║
║             | |_) / _ \| | | | '__|           ║
║             |  __/ (_) | |_| | |              ║
║    _   _    |_|  _\___/ \__,_|_|              ║
║   | | | |_ __   |_   _|__| | _(_) ___ _ __    ║
║   | | | | '_ \    | |/ _ \ |/ / |/ _ \ '_ \   ║
║   | |_| | | | |   | |  __/   <| |  __/ | | |  ║
║    \___/|_| |_|   |_|\___|_|\_\_|\___|_| |_|  ║
╚═══════════════════════════════════════════════╝

  ☄ 1. Mode Enseignant
  ☄ 2. Mode Etudiant
  ☄ 0. Quitter
```

---

## ✨ Fonctionnalités

- **Mode enseignant**, protégé par mot de passe :
  - créer un nouveau QCM (nom, catégorie, questions, 4 choix par question, bonne réponse) ;
  - choisir si les mauvaises réponses enlèvent des points ;
  - choisir un mode séquentiel (il faut répondre pour passer à la suite) ou libre ;
  - changer le mot de passe.
- **Mode étudiant** : choisir un QCM par catégorie, y répondre et obtenir sa note sur 20.
- **Sauvegarde dans des fichiers texte** : chaque QCM est un fichier `.txt`, rangé dans une catégorie.
- **Interface colorée** dans le terminal, avec contrôle des saisies (un message s'affiche si l'utilisateur tape autre chose qu'un nombre).

---

## 🧠 Ce que ce projet m'a appris

- Organiser un programme C en plusieurs fichiers (`main.c`, `fonction.c`, `fichier.h`).
- Utiliser des **structures** (`UneQuestion`, `ReglagesQcm`) pour représenter les données.
- **Lire et écrire des fichiers** (`fopen`, `fprintf`, `fscanf`) pour sauvegarder les QCM.
- Gérer les **saisies de l'utilisateur** sans que le programme plante.
- Compiler avec un **Makefile**.
- Travailler à deux avec **Git et GitHub**.

---

## 🚀 Installation et lancement

**Prérequis :** un compilateur C (`gcc`) et un terminal (Linux, macOS ou WSL sous Windows).

```bash
git clone https://github.com/Najm-eddine/Questions-pour-un-Tekien.git
cd Questions-pour-un-Tekien
make          # compile puis lance le programme
```

Autres commandes :

```bash
./qcm_tekien  # relancer le programme sans recompiler
make clean    # supprimer les fichiers objets (.o)
make mrproper # supprimer les fichiers objets et l'exécutable
```

Le mot de passe enseignant par défaut est `tekien`.

---

## 📚 QCM fournis

| Nom | Catégorie | Questions | Points négatifs | Mode séquentiel |
|---|---|---|---|---|
| football | Divers | 10 | Non | Oui |
| languageC | Informatique | 10 | Non | Non |
| Calculs | Mathématique | 10 | Oui | Oui |

---

## 📁 Structure du projet

```
├── main.c                  # boucle principale et menu
├── fonction.c              # modes enseignant / étudiant, création et passage des QCM
├── fichier.h               # structures, constantes et prototypes
├── Makefile                # compilation
├── cat_*.txt               # liste des QCM de chaque catégorie
├── football.txt, ...       # les QCM eux-mêmes
└── Rapport_Projet_QCM.pdf  # rapport du projet
```

📄 Le rapport complet est dans [`Rapport_Projet_QCM.pdf`](Rapport_Projet_QCM.pdf).
