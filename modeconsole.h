// ModeConsole.h
#ifndef MODE_CONSOLE_H
#define MODE_CONSOLE_H

#include "C:\Users\HP\OneDrive\Bureau\aaaaaaaaa\service\Game.h"
#include <string>

class ModeConsole {
public:
    ModeConsole(Game& game);
    void run(int iterations, bool enableToroidal); 
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);

private:
    Game& game;
    void displayGrid(std::ostream& out) const;
};

#endif // MODE_CONSOLE_H
