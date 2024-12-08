#include "ModeGraphics.h"
#include <iostream>

ModeGraphics::ModeGraphics(Game& game, int width, int height)
    : game(game),                        // Initialiser `game` en premier
      window(sf::VideoMode(width * 10, height * 10 + 100), "Jeu de la Vie"),
      isSimulationRunning(false),
      simulationSpeed(500) {

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
    bool isMousePressed = false; // Suivi de l'état du bouton de la souris

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                handleButtonClicks();

                if (event.mouseButton.button == sf::Mouse::Left) {
                    isMousePressed = true; // Marquer que la souris est pressée
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    isMousePressed = false; // Marquer que la souris est relâchée
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T) {
                game.getGrid().setToroidal(!game.getGrid().isToroidalEnabled());
                std::cout << "Grille torique " << (game.getGrid().isToroidalEnabled() ? "activée" : "désactivée") << "\n";
            }
        }

        // Gérer la mise à jour des cellules quand la souris est pressée
        if (isMousePressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            int gridX = mousePos.x / 10;
            int gridY = mousePos.y / 10;

            // Vérifiez si les indices sont dans les limites de la grille
            if (gridX >= 0 && gridX < game.getWidth() && gridY >= 0 && gridY < game.getHeight()) {
                Cell& cell = game.getGrid().getCell(gridX, gridY);
                cell.setState(cell.getState() == Cell::State::Alive ? Cell::State::Dead : Cell::State::Alive);
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
