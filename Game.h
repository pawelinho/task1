#ifndef GAME_H
#define GAME_H

#include "GameComponent.h"

typedef void (*FP)();

class Game
{
private:
    GameComponent *components[10];
    int componentCount;
    FP InitialiseFunction;
    FP TerminateFunction;

public:
    Game();
    void Add(GameComponent *component);
    void SetInitialise(FP func);
    void SetTerminate(FP func);
    void Run();
    ~Game();
};

#endif
