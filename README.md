## 📅 Gestion des Rendez-vous Médicaux (C)
Une application console en langage C permettant de gérer les rendez-vous patients.

## 🧾 Description
Ce programme en langage C offre une interface en mode texte pour gérer jusqu'à 100 rendez-vous de patients. Il propose des fonctionnalités complètes :
ajout, modification, suppression, tri, recherche, et statistiques sur les rendez-vous.

## 📦 Contenu
main.c : Code source principal du programme
README.md : Ce fichier de documentation

## 🚀 Fonctionnalités
- (1) Ajouter un rendez-vous
- (2) Modifier ou supprimer un rendez-vous
- (3) Afficher un ou tous les rendez-vous
- (4) Trier les rendez-vous (par nom, date ou statut)
- (5) Rechercher un rendez-vous par référence
- (6) Afficher des statistiques :
  * Moyenne d’âge
  * Tranches d’âge
  * Statuts (valide, reporté, annulé, traité)
- (7) Quitter le programme

## 🛠️ Compilation
Pour compiler le programme :
```bash
gcc -o rdv_app main.c
```

Pour exécuter le programme :
```bash
./rdv_app  # (ou rdv_app.exe sous Windows)
```

## 📋 Exemple d'utilisation
```txt
============== Menu Principal ==============
1- Ajouter un RDV
2- Modifier ou Supprimer un RDV
3- Afficher les details d'un RDV
4- Trier les RDV
5- Rechercher un RDV
6- Statistiques
7- Quitter
```
## ✅ Statuts disponibles
- valide 🟢
- reporte 🟡
- annule 🔴
- traite 🔵

## 💡 Remarques
- Le programme utilise la console Windows (system("cls"), system("pause")) — pour Linux/Mac, adaptez ces commandes.
- L'affichage utilise des codes couleurs ANSI pour améliorer la lisibilité (fonctionne mieux dans les terminaux compatibles).

## 📚 Auteurs
[Abderrahmane AHLALLAY]

## 📄 Licence
- Projet académique ou personnel
- libre d'utilisation et de modification.
