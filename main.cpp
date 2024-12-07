#include "../service/service.h/Game.h"
#include "../ihm/ihm.h/modegraphics.h"
#include "../ihm/ihm.h/modeconsole.h"
#include <iostream>
#include <string>
#include <fstream> // Pour std::ifstream

int main() {
    int mode;
    std::cout << "Choisissez le mode (1: Console, 2: Graphique): ";
    std::cin >> mode;

    if (mode == 1) {
        int gridWidth = 8;
        int gridHeight = 5;
        Game game(gridWidth, gridHeight);

        // Demander le nom du fichier
        std::string filename;
        std::cout << "Entrez le nom du fichier d'entrée (.txt) : ";
        std::cin >> filename;

        game.loadFromFile(filename); // Charger le fichier

        bool enableToroidal;
        std::cout << "Activer la grille torique ? (1: Oui, 0: Non): ";
        std::cin >> enableToroidal;

        ModeConsole consoleMode(game);
        consoleMode.run(5, enableToroidal); // Lancer la simulation
    } else if (mode == 2) {
        int gridWidth = 80;
        int gridHeight = 60;
        Game game(gridWidth, gridHeight);

        // Utiliser le chemin absolu pour le fichier
        game.loadFromFile("C:\\Users\\HP\\Downloads\\k\\input.txt");

        ModeGraphics graphicsMode(game, gridWidth, gridHeight);
        graphicsMode.run();
    } else {
        std::cout << "Mode invalide !" << std::endl;
    }

    return 0;
}
