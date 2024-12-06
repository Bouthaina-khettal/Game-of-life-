#include "GameGraphics.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

GameGraphics::GameGraphics(Grid& grid, int width, int height)
    : window(sf::VideoMode(width * 10, height * 10 + 100), "Game of Life"),
      grid(grid), isSimulationRunning(false), simulationSpeed(500) {
    // Initialisation des boutons
    startButton.setSize(sf::Vector2f(80, 40));
    startButton.setPosition(10, height * 10 + 10);
    startButton.setFillColor(sf::Color::Green);

    resetButton.setSize(sf::Vector2f(80, 40));
    resetButton.setPosition(100, height * 10 + 10);
    resetButton.setFillColor(sf::Color::Red);

    speedUpButton.setSize(sf::Vector2f(80, 40));
    speedUpButton.setPosition(190, height * 10 + 10);
    speedUpButton.setFillColor(sf::Color::Blue);
}

void GameGraphics::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                handleButtonClicks();
            }
        }

        if (isSimulationRunning) {
            // Mettre à jour la grille à chaque itération de la simulation
            updateGrid();  // Applique les règles de mise à jour de la grille
            sf::sleep(sf::milliseconds(simulationSpeed));  // Attendre pour réguler la vitesse
        }

        displayGrid();  // Afficher la grille après la mise à jour
    }
}

// Mise à jour de la grille selon les règles du jeu
void GameGraphics::updateGrid() {
    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            Cell& cell = grid.getCell(x, y);
            int aliveNeighbors = countAliveNeighbors(x, y);

            if (cell.getState() == CellState::ALIVE) {
                // Une cellule vivante reste vivante si elle a 2 ou 3 voisins vivants, sinon elle meurt
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    cell.setState(CellState::DEAD);
                }
            } else {
                // Une cellule morte devient vivante si elle a exactement 3 voisins vivants
                if (aliveNeighbors == 3) {
                    cell.setState(CellState::ALIVE);
                }
            }
        }
    }
}

// Fonction pour compter les voisins vivants
int GameGraphics::countAliveNeighbors(int x, int y) {
    int aliveCount = 0;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;  // Ignorer la cellule elle-même
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < grid.getWidth() && ny >= 0 && ny < grid.getHeight()) {
                if (grid.getCell(nx, ny).getState() == CellState::ALIVE) {
                    ++aliveCount;
                }
            }
        }
    }
    return aliveCount;
}

void GameGraphics::displayGrid() {
    window.clear();

    int cellSize = 10;  // Taille des cellules
    int spacing = 2;    // Espacement entre les cellules

    // Dessiner les cellules de la grille
    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(x * (cellSize + spacing), y * (cellSize + spacing));  // Appliquer l'espacement

            // Vérifier l'état de la cellule à la position (x, y)
            if (grid.getCell(x, y).getState() == CellState::ALIVE) {
                cell.setFillColor(sf::Color::White);  // Cellule vivante en blanc
            } else {
                cell.setFillColor(sf::Color::Black);  // Cellule morte en noir
            }

            window.draw(cell);  // Dessiner la cellule sur la fenêtre
        }
    }

    drawButtons();  // Dessiner les boutons
    window.display();  // Mettre à jour la fenêtre
}


void GameGraphics::drawButtons() {
    window.draw(startButton);
    window.draw(resetButton);
    window.draw(speedUpButton);  // Dessiner le bouton pour accélérer la vitesse
}

void GameGraphics::handleButtonClicks() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    // Vérifier si le bouton Start est cliqué
    if (startButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        isSimulationRunning = !isSimulationRunning;  // Basculer l'état de la simulation
    }
    // Vérifier si le bouton Reset est cliqué
    else if (resetButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        // Réinitialiser la grille
        for (int y = 0; y < grid.getHeight(); ++y) {
            for (int x = 0; x < grid.getWidth(); ++x) {
                if ((x + y) % 2 == 0) {
                    grid.getCell(x, y).setState(CellState::ALIVE);
                } else {
                    grid.getCell(x, y).setState(CellState::DEAD);
                }
            }
        }
    }
    // Vérifier si le bouton Speed Up est cliqué
    else if (speedUpButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        if (simulationSpeed > 100) {
            simulationSpeed -= 100;  // Accélérer la simulation
        }
    }
}

