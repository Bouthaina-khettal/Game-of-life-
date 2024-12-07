// modegraphics.cpp
#include "ModeGraphics.h"
#include <iostream>

ModeGraphics::ModeGraphics(Game& game, int width, int height)
    : window(sf::VideoMode(width * 10, height * 10 + 100), "Jeu de la Vie"),
      game(game), isSimulationRunning(false), simulationSpeed(500) {

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

void ModeGraphics::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                handleButtonClicks();

                if (event.mouseButton.button == sf::Mouse::Left) {
                    int gridX = event.mouseButton.x / 10;
                    int gridY = event.mouseButton.y / 10;

                    if (gridX >= 0 && gridX < game.getWidth() && gridY >= 0 && gridY < game.getHeight()) {
                        Cell& cell = game.getGrid().getCell(gridX, gridY);
                        cell.setState(cell.getState() == Cell::State::Alive ? Cell::State::Dead : Cell::State::Alive);
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T) {
                game.getGrid().setToroidal(!game.getGrid().isToroidalEnabled());
                std::cout << "Grille torique " << (game.getGrid().isToroidalEnabled() ? "activée" : "désactivée") << "\n";
            }
        }

        if (isSimulationRunning) {
            game.update();
            sf::sleep(sf::milliseconds(simulationSpeed));
        }

        displayGrid();
    }
}

void ModeGraphics::displayGrid() {
    window.clear();

    int cellSize = 10;
    for (int y = 0; y < game.getHeight(); ++y) {
        for (int x = 0; x < game.getWidth(); ++x) {
            sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
            cell.setPosition(x * cellSize, y * cellSize);

            if (game.getState(x, y) == Cell::State::Alive) {
                cell.setFillColor(sf::Color::White);
            } else {
                cell.setFillColor(sf::Color::Black);
            }

            window.draw(cell);
        }
    }

    drawButtons();
    window.display();
}

void ModeGraphics::drawButtons() {
    window.draw(startButton);
    window.draw(resetButton);
    window.draw(speedUpButton);
}

void ModeGraphics::handleButtonClicks() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (startButton.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y)) {
        isSimulationRunning = !isSimulationRunning;
        std::cout << "Bouton Start cliqué : Simulation "
                  << (isSimulationRunning ? "démarrée" : "arrêtée") << "\n";
    } else if (resetButton.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y)) {
        std::cout << "Bouton Reset cliqué\n";
        for (int y = 0; y < game.getHeight(); ++y) {
            for (int x = 0; x < game.getWidth(); ++x) {
                game.getGrid().getCell(x, y).setState(Cell::State::Dead);
            }
        }
    } else if (speedUpButton.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y)) {
        if (simulationSpeed > 100) {
            simulationSpeed -= 100;
            std::cout << "Bouton SpeedUp cliqué : Nouvelle vitesse = " << simulationSpeed << " ms\n";
        }
    }
}
