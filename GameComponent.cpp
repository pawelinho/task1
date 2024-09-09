#include "GameComponent.h"
#include <iostream>
using namespace std;

// Initialising total instances tracker
int GameComponent::instances = 0;

// Unique id based on instances
GameComponent::GameComponent()
{
    id = ++instances; // using the instance variable as a unique ID
}

// Displaying ID and current time
void GameComponent::Update(int time)
{
    cout << "GameComponent " << id << " updated at time " << time << endl;
}

// Destructor
GameComponent::~GameComponent()
{
}
