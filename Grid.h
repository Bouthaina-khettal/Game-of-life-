#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>
#include <string> // Pour les chaînes de caractères

class Grid {
public:
    // Constructeur
    Grid(int width, int height);

    // Accesseurs
    Cell& getCell(int x, int y);
    const Cell& getCell(int x, int y) const;

    // Méthodes pour gérer la grille
    int getWidth() const;
    int getHeight() const;
    void update();
    void saveToFile(const std::string& filename) const;
    void initializeFromFile(const std::string& filename);
    void display() const;
    void simulate(const std::string& outputFile, int maxIterations = 5);

private:
    int width, height;
    std::vector<std::vector<Cell>> cells; // Matrice de cellules
    void applyRules(); // Applique les règles du Jeu de la Vie
       int rows, cols;
    int** gridData; 
};

#endif // GRID_H



