#include <SFML/Graphics.hpp>
#include "LEM.h"

class Game
{
private:
    sf::RenderWindow *window;
    LEM lem;

public:
    Game();
    void run();
    void update();
    void render();
};