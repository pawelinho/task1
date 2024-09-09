#ifndef DRAWABLEGAMECOMPONENT_H
#define DRAWABLEGAMECOMPONENT_H

#include "GameComponent.h"

class DrawableGameComponent : public GameComponent
{
private:
    int x, y;
    enum Direction
    {
        Up,
        Down,
        Left,
        Right
    } direction;
    void ChangeDirection();
    void Draw();

public:
    DrawableGameComponent();
    void Update(int time) override;
};

#endif
