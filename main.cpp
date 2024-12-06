#include "Grid.h"
#include "GameGraphics.h"
#include <iostream>

int main() {
    int mode;
    std::cout << "Choisissez le mode (1: Console, 2: Graphique): ";
    std::cin >> mode;

    if (mode == 1) {
        // Mode console : créer une grille 8x5
        int gridWidth = 8;
        int gridHeight = 5;
        Grid grid(gridWidth, gridHeight);

        // Initialiser la grille à partir du fichier
        grid.initializeFromFile("input.txt");

        // Appel à la méthode simulate pour gérer les itérations et l'enregistrement dans un fichier
        grid.simulate("output.txt", 5); // Limiter à 5 itérations et sauvegarder dans "output.txt"
    } else if (mode == 2) {
        // Mode graphique : créer une grille 80x60
        int gridWidth = 80;
        int gridHeight = 60;
        Grid grid(gridWidth, gridHeight);

        // Lancer la simulation graphique
        GameGraphics gameGraphics(grid, gridWidth, gridHeight);
        gameGraphics.run();
    } else {
        std::cout << "Mode non valide!" << std::endl;
    }

    return 0;
}

  