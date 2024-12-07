// ModeGraphics.h
#ifndef MODE_GRAPHICS_H
#define MODE_GRAPHICS_H

#include "Game.h"
#include <SFML/Graphics.hpp>

class ModeGraphics {
public:
    ModeGraphics(Game& game, int width, int height);
    void run();

private:
    Game& game;
    sf::RenderWindow window;
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
