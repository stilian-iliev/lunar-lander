
#include "GameController.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Lunar Lander");
    LunarLander lander(400, 500, 0);
    GameController game(window, lander);
    game.Run();
}