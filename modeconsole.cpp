// modeconsole.cpp
#include "ModeConsole.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

ModeConsole::ModeConsole(Game& game) : game(game) {}

void ModeConsole::run(int iterations, bool enableToroidal) {
    game.getGrid().setToroidal(enableToroidal);

    for (int i = 0; i < iterations; ++i) {
        std::cout << "Iteration " << i + 1 << ":\n";
        displayGrid();

        game.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void ModeConsole::displayGrid() const {
    const Grid& grid = game.getGrid();
    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            std::cout << (grid.getCell(x, y).getState() == Cell::State::Alive ? "1" : "0") << " ";
        }
        std::cout << "\n";
    }
}

void ModeConsole::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << "\n";
        return;
    }

    int y = 0;
    std::string line;
    while (std::getline(file, line)) {
        for (int x = 0; x < (int)line.size() && x < game.getGrid().getWidth(); ++x) {
            if (line[x] == '1') {
                game.getGrid().getCell(x, y).setState(Cell::State::Alive);
            } else {
                game.getGrid().getCell(x, y).setState(Cell::State::Dead);
            }
        }
        ++y;
        if (y >= game.getGrid().getHeight()) break;
    }

    file.close();
    std::cout << "Grille chargée depuis " << filename << "\n";
}

void ModeConsole::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible de sauvegarder dans le fichier " << filename << "\n";
        return;
    }

    const Grid& grid = game.getGrid();
    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            file << (grid.getCell(x, y).getState() == Cell::State::Alive ? "1" : "0");
        }
        file << "\n";
    }

    file.close();
    std::cout << "Grille sauvegardée dans " << filename << "\n";
}
