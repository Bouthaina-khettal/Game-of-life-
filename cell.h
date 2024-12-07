// cell.h
#ifndef CELL_H
#define CELL_H

class Cell {
public:
    enum class State { Dead, Alive };

    Cell() : state(State::Dead) {}

    State getState() const { return state; }
    void setState(State s) { state = s; }

private:
    State state;
};

#endif // CELL_H
