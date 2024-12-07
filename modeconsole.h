// ModeConsole.h
#ifndef MODE_CONSOLE_H
#define MODE_CONSOLE_H

#include "Game.h"
#include <string>

class ModeConsole {
public:
    ModeConsole(Game& game);
    void run(int iterations, bool enableToroidal); 
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);

private:
    Game& game;
    void displayGrid() const;
};

#endif // MODE_CONSOLE_H
