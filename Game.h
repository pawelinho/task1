#ifndef GAME_H
#define GAME_H

#include "GameComponent.h"

// Typedef for function pointers
typedef void (*FP)();

// Game Class
class Game
{
private:
    GameComponent *components[10]; // Array storig game components
    int componentCount;            // component count tracker
    FP InitialiseFunction;         // initialise function pointer
    FP TerminateFunction;          // termination function pointer

public:
    Game();                             // Constructor
    void Add(GameComponent *component); // Adds a game component
    void SetInitialise(FP func);        // Sets the Initialise fp
    void SetTerminate(FP func);         // Sets the Terminate fp
    void Run();                         // Runing the game
    ~Game();                            // Destructor
};

#endif
