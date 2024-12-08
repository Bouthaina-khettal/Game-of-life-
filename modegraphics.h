// ModeGraphics.h
#ifndef MODE_GRAPHICS_H
#define MODE_GRAPHICS_H

#include "C:\Users\HP\OneDrive\Bureau\aaaaaaaaa\service\Game.h"
#include <SFML/Graphics.hpp>

class ModeGraphics {
public:
    ModeGraphics(Game& game, int width, int height);
    void run();

private:
    Game& game;                   // Déclarer d'abord `game`
    sf::RenderWindow window;       // Puis `window`
    bool isSimulationRunning;
    int simulationSpeed;

    sf::RectangleShape startButton;
    sf::RectangleShape resetButton;
    sf::RectangleShape speedUpButton;

    void displayGrid();
    void drawButtons();
    void handleButtonClicks();
};

#endif // MODE_GRAPHICS_H
