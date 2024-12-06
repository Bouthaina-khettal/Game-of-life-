#ifndef GAME_H
#define GAME_H

#include "Grid.h"

#include <string>
class Game {
public:
    Game(int width, int height);
    void run(int maxIterations);
    void saveGameState(const std::string& filename) const;

private:
    Grid grid;
};

#endif




