#ifndef CELL_H
#define CELL_H

enum class CellState {
    DEAD,
    ALIVE
};

class Cell {
public:
    // Constructeur avec état par défaut
    Cell(CellState state = CellState::DEAD);

    // Getter et Setter
    CellState getState() const;
    void setState(CellState newState);

    // Fonction pour inverser l'état de la cellule
    void toggleState();

private:
    CellState state;  // L'état de la cellule
};

#endif


