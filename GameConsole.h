#ifndef GAMECONSOLE_H
#define GAMECONSOLE_H

#include "Game.h"
#include <string>

class GameConsole {
public:
    GameConsole(const std::string& inputFile);
    void run();

private:
    Game game;
    int maxIterations;
};

#endif


