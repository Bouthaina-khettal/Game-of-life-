#include "Cell.h"

Cell::Cell(CellState state) : state(state) {}

CellState Cell::getState() const {
    return state;
}

void Cell::setState(CellState newState) {
    state = newState;
}

void Cell::toggleState() {
    state = (state == CellState::ALIVE) ? CellState::DEAD : CellState::ALIVE;
}




