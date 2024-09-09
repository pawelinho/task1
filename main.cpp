#include "Game.h"
#include "DrawableGameComponent.h"
#include <iostream>
#include <cstdlib> // For srand and rand
#include <ctime>   // For time function to seed random generator
using namespace std;

// Function to initialise the game
void Initialise()
{
    cout << "Initialising game" << endl;
}

// Function to terminate game
void Terminate()
{
    cout << "Terminating game" << endl;
}

int main()
{
    // Seeding the random number generator with the current time to have different random sequence 
    srand(time(NULL)); 

    // Creates a new Game object dynamically
    Game *game = new Game();

    game->SetInitialise(Initialise);
    game->SetTerminate(Terminate);

    // Adding a GameComponent and a DrawableGameComponent to game
    game->Add(new GameComponent());
    game->Add(new DrawableGameComponent());

    // Runing the game
    game->Run();

    // Cleaning up the game object
    delete game;

    return 0;
}
