#include "DrawableGameComponent.h"
#include <iostream>
#include <cstdlib> // rand() and srand()
using namespace std;

// initializes x, y to 0 and sets the direction to Right
DrawableGameComponent::DrawableGameComponent() : GameComponent(), x(0), y(0), direction(Right) {}

void DrawableGameComponent::Update(int time)
{
    cout << "DrawableGameComponent " << id << " updated at time " << time << endl;

    // Update the position based on the current direction
    switch (direction)
    {
    case Up:
        if (y > 0)
            y--;
        break; // Move up but not below 0
    case Down:
        if (y < 20)
            y++;
        break; // Move down, but up to 20
    case Left:
        if (x > 0)
            x--;
        break; // Move left, but not below 0
    case Right:
        if (x < 80)
            x++;
        break; // Move right, but up to  80
    }

    Draw();            // Drawing the new position and direction
    ChangeDirection(); // Changing the direction to a new random direction
}

// Prints the current direction and position coordinates
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
        newDirection = static_cast<Direction>(rand() % 4); // assigning a new direction based on random number between 0 and 3
    } while (newDirection == direction); // TODO: improve performance of this
    direction = newDirection;
}
