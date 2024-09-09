#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

// Base class
class GameComponent {
protected:
    static int instances; // number of instances tracker
    int id;               // Unique ID for each component

public:
    GameComponent();      // Constructor
    virtual void Update(int time);  // Virtual Update function
    virtual ~GameComponent();       // Virtual destructor 
};

#endif
