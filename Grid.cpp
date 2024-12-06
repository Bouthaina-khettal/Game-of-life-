#include "Grid.h"
#include <fstream>
#include <iostream>

Grid::Grid(int width, int height) : width(width), height(height) {
    cells.resize(height, std::vector<Cell>(width));
}

Cell& Grid::getCell(int x, int y) {
    return cells[y][x];
}

const Cell& Grid::getCell(int x, int y) const {
    return cells[y][x];
}

int Grid::getWidth() const {
    return width;
}

int Grid::getHeight() const {
    return height;
}
void Grid::applyRules() {
    std::vector<std::vector<CellState>> newStates(height, std::vector<CellState>(width));

    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            int liveNeighbors = 0;

            // Vérification des voisins
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dx == 0 && dy == 0) continue;
                    if (getCell(x + dx, y + dy).getState() == CellState::ALIVE) {
                        ++liveNeighbors;
                    }
                }
            }

            // Application des règles du jeu
            if (getCell(x, y).getState() == CellState::ALIVE) {
                newStates[y][x] = (liveNeighbors == 2 || liveNeighbors == 3) ? CellState::ALIVE : CellState::DEAD;
            } else {
                newStates[y][x] = (liveNeighbors == 3) ? CellState::ALIVE : CellState::DEAD;
            }
        }
    }

    // Mise à jour de la grille avec les nouveaux états
    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            getCell(x, y).setState(newStates[y][x]);
        }
    }
} 

void Grid::update() {
    applyRules();
}

void Grid::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::app);  // Ouvrir le fichier en mode ajout (append)
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'écrire dans le fichier " << filename << std::endl;
        return;
    }

    // Affiche chaque ligne de la grille dans le fichier
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            file << (getCell(x, y).getState() == CellState::ALIVE ? '1' : '0');
        }
        file << std::endl;  // Nouvelle ligne après chaque ligne de la grille
    }

    file.close();  // Assurez-vous que le fichier est bien fermé après l'écriture
}



void Grid::initializeFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }

    for (int y = 0; y < height; ++y) {
        std::string line;
        if (std::getline(file, line)) {
            for (int x = 0; x < width && x < line.size(); ++x) {
                if (line[x] == '1') {
                    getCell(x, y).setState(CellState::ALIVE);
                } else {
                    getCell(x, y).setState(CellState::DEAD);
                }
            }
        }
    }

    file.close();
}
void Grid::display() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << (getCell(x, y).getState() == CellState::ALIVE ? '1' : '0') << " ";
        }
        std::cout << std::endl;
    }
}
void Grid::simulate(const std::string& outputFile, int maxIterations) {
    std::ofstream output(outputFile);
    if (!output.is_open()) {
        std::cerr << "Erreur : impossible d'écrire dans le fichier " << outputFile << std::endl;
        return;
    }

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        std::cout << "Iteration " << iteration + 1 << ":" << std::endl;
        display();  // Affichage de l'état actuel de la grille
        saveToFile(outputFile);  // Sauvegarde de l'état dans le fichier

        update();  // Application des règles du jeu
        output << "Iteration " << iteration + 1 << ":" << std::endl;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                output << (getCell(x, y).getState() == CellState::ALIVE ? '1' : '0') << " ";
            }
            output << std::endl;
        }
        output << std::endl;
    }

    output.close();
}



