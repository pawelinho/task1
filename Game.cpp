#include "Game.h"
#include <iostream>
#include <thread> 
#include <chrono> 
using namespace std;

Game::Game() : componentCount(0), InitialiseFunction(nullptr), TerminateFunction(nullptr) {}

// Adds a component (up to 10 components)
void Game::Add(GameComponent *component)
{
    if (componentCount < 10)
    {
        components[componentCount++] = component;
    }
}

// Assigns a function pointer to the InitialiseFunction
void Game::SetInitialise(FP func)
{
    InitialiseFunction = func;
}

// Assigns a function pointer to the TerminateFunction
void Game::SetTerminate(FP func)
{
    TerminateFunction = func;
}

// Run function doing the game loop, updating components and calls the Initialise and Terminate functions
void Game::Run()
{
    if (InitialiseFunction)
    {
        InitialiseFunction(); // Call the initialize function
    }

    // Loop for 5 iterations (representing 5 seconds)
    for (int i = 0; i < 5; ++i)
    {
        // Update each component
        for (int j = 0; j < componentCount; ++j)
        {
            components[j]->Update(i + 1);
        }
        this_thread::sleep_for(chrono::seconds(1)); // Sleep for 1 second between updates
    }

    if (TerminateFunction)
    {
        TerminateFunction(); // Call the terminate function
    }
}

// Destructor Cleans up the components
Game::~Game()
{
    for (int i = 0; i < componentCount; ++i)
    {
        delete components[i];
    }
}
