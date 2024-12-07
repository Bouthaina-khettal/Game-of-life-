#ifndef MODE_H
#define MODE_H

#include "Game.h"  // Inclure la classe Game pour l'accès au jeu

class Mode {
public:
    // Constructeur avec un objet Game pour être utilisé dans tous les modes
    Mode(Game& game) : game(game) {}

    // Méthode virtuelle pure pour démarrer la simulation (devra être implémentée dans les classes dérivées)
    virtual void run() = 0;

protected:
    Game& game;  // Référence à l'objet Game pour manipuler le jeu dans chaque mode
};

#endif // MODE_H

