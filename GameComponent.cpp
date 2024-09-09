#include "GameComponent.h"
#include <iostream>
using namespace std;

int GameComponent::instances = 0;

GameComponent::GameComponent()
{
    id = ++instances;
}

void GameComponent::Update(int time)
{
    cout << "GameComponent " << id << " updated at time " << time << endl;
}

GameComponent::~GameComponent()
{
    // Destructor logic if needed
}
