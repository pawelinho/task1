#include "Game.h"
#include "DrawableGameComponent.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void Initialise()
{
    cout << "Initialising game" << endl;
}

void Terminate()
{
    cout << "Terminating game" << endl;
}

int main()
{
    srand(time(NULL));

    Game *game = new Game();

    game->SetInitialise(Initialise);
    game->SetTerminate(Terminate);

    game->Add(new GameComponent());
    game->Add(new DrawableGameComponent());

    game->Run();

    delete game;

    return 0;
}
