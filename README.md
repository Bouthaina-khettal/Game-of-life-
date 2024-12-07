
# Projet : Jeu de la vie en c++ poo

## Description

Ce projet implémente le célèbre "Jeu de la Vie" de John Conway, une simulation d'automate cellulaire. Le jeu se déroule sur une grille où chaque cellule peut être vivante ou morte. Les cellules évoluent à chaque itération selon des règles simples basées sur le nombre de voisins vivants.

## Contenu du projet

### Structure des fichiers

#### Code source principal
- `Game.cpp` / `Game.h` : Contiennent la logique principale du jeu.
- `cell.cpp` / `cell.h` : Gestion des cellules utilisées dans le jeu.
- `grid.cpp` / `grid.h` : Gestion de la grille du jeu.
- `mode.h` : Définit les modes de jeu (console ou graphique).
- `modeconsole.cpp` / `modeconsole.h` : Implémentation du mode console.
- `modegraphics.cpp` / `modegraphics.h` : Implémentation du mode graphique.
#### Fichiers supplémentaires
- `input2.txt` : Contient des données d'entrée pour le programme.
- `c_cpp_properties.json` : Configuration du compilateur pour un environnement C++ (probablement Visual Studio Code).


## Fonctionnalités

- Simulation en mode console et graphique.
- Chargement et sauvegarde de l'état de la grille à partir de fichiers.
- Affichage de l'état de la grille en temps réel.
## Mode Console
Le mode console permet d'interagir avec le jeu via un terminal. Voici ses principales fonctionnalités :

### Exécution de la simulation (run) :

La méthode prend deux paramètres : le nombre d'itérations et un booléen pour activer/désactiver le mode torique.
Affiche l'état de la grille à chaque itération, avec un délai de 500 ms entre les mises à jour.
Appelle la méthode update() de la classe Game pour recalculer l'état de la grille.
### Chargement de la grille depuis un fichier (loadFromFile) :

Lit un fichier texte où chaque ligne correspond à une rangée de cellules (1 pour vivantes, 0 pour mortes).
Met à jour les cellules de la grille en fonction du contenu du fichier.

### Affichage de la grille (displayGrid) :

Parcourt chaque cellule de la grille.
Affiche 1 pour une cellule vivante et 0 pour une cellule morte.

### Sauvegarde de la grille dans un fichier (saveToFile) :

Écrit l'état actuel de la grille dans un fichier texte, ligne par ligne.
Chaque cellule est représentée par 1 ou 0.
## Mode Graphique
Le mode graphique offre une interface utilisateur interactive basée sur la bibliothèque SFML. Voici ses principales fonctionnalités :

### Exécution de la simulation (run) :

Gère les événements utilisateur (fermeture de la fenêtre, clics de souris, appuis sur des touches).
Permet d'activer/désactiver le mode torique avec la touche T.
Si la simulation est en cours, elle appelle update() pour faire évoluer la grille et attend une durée définie par simulationSpeed.
### Affichage de la grille (displayGrid) :

Dessine chaque cellule de la grille en tant que rectangle.
Les cellules vivantes sont blanches, et les mortes, noires.
Les boutons (start, reset, speed up) sont également affichés.
### Gestion des boutons (handleButtonClicks) :

Bouton Start : Démarre ou arrête la simulation.
Bouton Reset : Réinitialise la grille en mettant toutes les cellules à l'état mort.
Bouton Speed Up : Réduit la durée entre les mises à jour (vitesse accrue).
### Mode interactif :
Permet de cliquer sur une cellule de la grille pour basculer son état (vivante/morte).
Les clics de souris sont capturés pour modifier directement l'état des cellules.

## Prérequis
Avant de compiler et d'exécuter le projet, assurez-vous d'avoir les éléments suivants :
- C++ 
- La bibliothèque graphique nécessaire SFML (pour le mode graphique)
- Un compilateur C++ (comme `g++`).
- Un éditeur de texte ou IDE (comme Visual Studio Code ou visual studio).

 ## Comment lancer le jeu? 
 
 
