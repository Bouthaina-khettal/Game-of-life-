// Game.cpp
#include "Game.h"
#include <fstream>
#include <iostream>

Game::Game(int width, int height) : grid(width, height) {}

void Game::update() {
    Grid newGrid = grid;
    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            int aliveNeighbors = grid.countAliveNeighbors(x, y);
            if (grid.getCell(x, y).getState() == Cell::State::Alive) {
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    newGrid.getCell(x, y).setState(Cell::State::Dead);
                }
            } else {
                if (aliveNeighbors == 3) {
                    newGrid.getCell(x, y).setState(Cell::State::Alive);
                }
            }
        }
    }
    grid = newGrid;
}

const Grid& Game::getGrid() const {
    return grid;
}

Grid& Game::getGrid() {
    return grid;
}

Cell::State Game::getState(int x, int y) const {
    return grid.getCell(x, y).getState();
}

int Game::getWidth() const {
    return grid.getWidth();
}

int Game::getHeight() const {
    return grid.getHeight();
}

void Game::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << "\n";
        return;
    }

    int y = 0;
    std::string line;
    while (std::getline(file, line)) {
        for (int x = 0; x < (int)line.size() && x < grid.getWidth(); ++x) {
            if (line[x] == '1') {
                grid.getCell(x, y).setState(Cell::State::Alive);
            } else {
                grid.getCell(x, y).setState(Cell::State::Dead);
            }
        }
        ++y;
        if (y >= grid.getHeight()) break;
    }

    file.close();
    std::cout << "Grille chargée depuis " << filename << "\n";
}
