// Grid.h
#ifndef GRID_H
#define GRID_H

#include <vector>
#include "cell.h"

class Grid {
public:
    Grid(int width, int height);

    int getWidth() const;
    int getHeight() const;
    Cell& getCell(int x, int y);
    const Cell& getCell(int x, int y) const;

    void setToroidal(bool enable);
    bool isToroidalEnabled() const;

    int countAliveNeighbors(int x, int y) const;

private:
    int width, height;
    bool toroidal = false;
    std::vector<std::vector<Cell>> cells;

    int wrapCoordinate(int coordinate, int max) const;
};

#endif // GRID_H
