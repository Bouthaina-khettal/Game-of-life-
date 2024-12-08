// Grid.cpp
#include "Grid.h"

Grid::Grid(int width, int height) : width(width), height(height) {
    cells.resize(height, std::vector<Cell>(width));
}

int Grid::getWidth() const {
    return width;
}

int Grid::getHeight() const {
    return height;
}

Cell& Grid::getCell(int x, int y) {
    if (toroidal) {
        x = wrapCoordinate(x, width);
        y = wrapCoordinate(y, height);
    }
    return cells[y][x];
}

const Cell& Grid::getCell(int x, int y) const {
    if (toroidal) {
        x = wrapCoordinate(x, width);
        y = wrapCoordinate(y, height);
    }
    return cells[y][x];
}

void Grid::setToroidal(bool enable) {
    toroidal = enable;
}

bool Grid::isToroidalEnabled() const {
    return toroidal;
}

int Grid::countAliveNeighbors(int x, int y) const {
    int aliveNeighbors = 0;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;

            int nx = x + dx;
            int ny = y + dy;

            if (toroidal) {
                nx = wrapCoordinate(nx, width);
                ny = wrapCoordinate(ny, height);
            }

            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                if (cells[ny][nx].getState() == Cell::State::Alive) {
                    ++aliveNeighbors;
                }
            }
        }
    }
    return aliveNeighbors;
}

int Grid::wrapCoordinate(int coordinate, int max) const {
    if (coordinate < 0) return max - 1;
    if (coordinate >= max) return 0;
    return coordinate;
}
