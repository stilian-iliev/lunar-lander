#include <SFML/Graphics.hpp>
#include "LEM.cpp"

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