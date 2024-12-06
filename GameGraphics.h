#ifndef GAMEGRAPHICS_H
#define GAMEGRAPHICS_H

#include <SFML/Graphics.hpp>
#include "Grid.h"

class GameGraphics {
private:
    sf::RenderWindow window;  // Fenêtre graphique
    Grid& grid;               // Grille du jeu
    bool isSimulationRunning; // Indique si la simulation est en cours
    int simulationSpeed;      // Vitesse de simulation en millisecondes

    sf::RectangleShape startButton; // Bouton pour démarrer/arrêter
    sf::RectangleShape resetButton; // Bouton pour réinitialiser
    sf::RectangleShape speedUpButton; // Bouton pour accélérer

    void handleButtonClicks(); // Gère les clics sur les boutons
    void drawButtons();        // Affiche les boutons
    void updateGrid();         // Met à jour la grille selon les règles du jeu
    int countAliveNeighbors(int x, int y); // Compte les voisins vivants d'une cellule

public:
    GameGraphics(Grid& grid, int width, int height);
    void run();                // Lancer la simulation
    void displayGrid();        // Afficher la grille
};

#endif





