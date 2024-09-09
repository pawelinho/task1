#include "DrawableGameComponent.h"
#include <iostream>
#include <cstdlib>
using namespace std;

DrawableGameComponent::DrawableGameComponent() : GameComponent(), x(0), y(0), direction(Right) {}

void DrawableGameComponent::Update(int time)
{
    cout << "DrawableGameComponent " << id << " updated at time " << time << endl;

    switch (direction)
    {
    case Up:
        if (y > 0)
            y--;
        break;
    case Down:
        if (y < 20)
            y++;
        break;
    case Left:
        if (x > 0)
            x--;
        break;
    case Right:
        if (x < 80)
            x++;
        break;
    }

    Draw();
    ChangeDirection();
}

void DrawableGameComponent::Draw()
{
    cout << "Direction: ";
    switch (direction)
    {
    case Up:
        cout << "Up";
        break;
    case Down:
        cout << "Down";
        break;
    case Left:
        cout << "Left";
        break;
    case Right:
        cout << "Right";
        break;
    }
    cout << " | Position: (" << x << ", " << y << ")" << endl;
}

void DrawableGameComponent::ChangeDirection()
{
    Direction newDirection;
    do
    {
        newDirection = static_cast<Direction>(rand() % 4);
    } while (newDirection == direction);
    direction = newDirection;
}
