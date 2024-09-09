#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

Game::Game() : componentCount(0), InitialiseFunction(nullptr), TerminateFunction(nullptr) {}

void Game::Add(GameComponent *component)
{
    if (componentCount < 10)
    {
        components[componentCount++] = component;
    }
}

void Game::SetInitialise(FP func)
{
    InitialiseFunction = func;
}

void Game::SetTerminate(FP func)
{
    TerminateFunction = func;
}

void Game::Run()
{
    if (InitialiseFunction)
    {
        InitialiseFunction();
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < componentCount; ++j)
        {
            components[j]->Update(i + 1);
        }
        this_thread::sleep_for(chrono::seconds(1));
    }

    if (TerminateFunction)
    {
        TerminateFunction();
    }
}

Game::~Game()
{
    for (int i = 0; i < componentCount; ++i)
    {
        delete components[i];
    }
}
