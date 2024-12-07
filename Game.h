// Game.h
#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include <string>

class Game {
public:
    Game(int width, int height);

    void update();
    const Grid& getGrid() const;
    Grid& getGrid();
    Cell::State getState(int x, int y) const;

    int getWidth() const;
    int getHeight() const;

    void loadFromFile(const std::string& filename);

private:
    Grid grid;
};

#endif // GAME_H
