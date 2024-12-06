#include "Game.h"
#include <iostream>

Game::Game(int width, int height) : grid(width, height) {
  grid.initializeFromFile("input.txt");
}

void Game::run(int maxIterations) {
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        grid.saveToFile("iteration_" + std::to_string(iteration) + ".out");
        grid.update();
    }
}

void Game::saveGameState(const std::string& filename) const {
    grid.saveToFile(filename);
}

