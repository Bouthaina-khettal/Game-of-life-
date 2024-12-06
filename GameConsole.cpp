#include "GameConsole.h"
#include <iostream>
#include <fstream>
#include <sstream>

GameConsole::GameConsole(const std::string& inputFile) : game(10, 10) {
    std::ifstream file(inputFile);
    if (file.is_open()) {
        file >> maxIterations;
    } else {
        maxIterations = 10;  // Valeur par défaut
    }
}

void GameConsole::run() {
    game.run(maxIterations);
}


