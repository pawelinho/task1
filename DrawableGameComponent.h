#ifndef DRAWABLEGAMECOMPONENT_H
#define DRAWABLEGAMECOMPONENT_H

#include "GameComponent.h"

class DrawableGameComponent : public GameComponent
{
private:
    int x, y; // x and y coordinates for the 2D position
    enum Direction
    {
        Up,
        Down,
        Left,
        Right
    } direction;            
    void ChangeDirection(); // Changes directions randomly
    void Draw();            // Draws position and direction

public:
    DrawableGameComponent();        // Constructor initialises the x,  y and direction
    void Update(int time) override; // Overridde update function to update position and draw
};

#endif
