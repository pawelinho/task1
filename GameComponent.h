#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

class GameComponent
{
protected:
    static int instances;
    int id;

public:
    GameComponent();
    virtual void Update(int time);
    virtual ~GameComponent();
};

#endif
