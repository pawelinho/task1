#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

typedef void (*FP)();

void Initialise()
{
    cout << "Initialising game" << endl;
}

void Terminate()
{
    cout << "Terminating game" << endl;
}

class GameComponent
{
protected:
    static int instances;
    int id;

public:
    GameComponent()
    {
        id = ++instances;
    }

    virtual void Update(int time)
    {
        cout << "GameComponent " << id << " updated at time " << time << endl;
    }

    virtual ~GameComponent() {}
};

int GameComponent::instances = 0;

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

    void ChangeDirection()
    {
        Direction newDirection;
        do
        {
            newDirection = static_cast<Direction>(rand() % 4);
        } while (newDirection == direction);
        direction = newDirection;
    }

    void Draw()
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

public:
    DrawableGameComponent() : GameComponent(), x(0), y(0), direction(Right) {}

    void Update(int time) override
    {
        cout << "DrawableGameComponent " << id << " updated at time " << time << endl;

        // Update position based on direction
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
};

class Game
{
private:
    GameComponent *components[10];
    int componentCount;
    FP InitialiseFunction;
    FP TerminateFunction;

public:
    Game() : componentCount(0), InitialiseFunction(nullptr), TerminateFunction(nullptr) {}

    void Add(GameComponent *component)
    {
        if (componentCount < 10)
        {
            components[componentCount++] = component;
        }
    }

    void SetInitialise(FP func)
    {
        InitialiseFunction = func;
    }

    void SetTerminate(FP func)
    {
        TerminateFunction = func;
    }

    void Run()
    {
        if (InitialiseFunction)
        {
            InitialiseFunction();
        }

        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < componentCount; ++j)
            {
                components[j]->Update(i + 1);
            }
            this_thread::sleep_for(chrono::seconds(1));
        }

        if (TerminateFunction)
        {
            TerminateFunction();
        }
    }

    ~Game()
    {
        for (int i = 0; i < componentCount; ++i)
        {
            delete components[i];
        }
    }
};

int main()
{
    srand(time(0));

    Game *game = new Game();

    game->SetInitialise(Initialise);
    game->SetTerminate(Terminate);

    game->Add(new GameComponent());
    game->Add(new DrawableGameComponent());

    game->Run();

    delete game;

    return 0;
}
