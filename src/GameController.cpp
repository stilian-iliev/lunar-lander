#include <SFML/Graphics.hpp>
#include "LunarSurface.cpp"
#include "LunarLander.cpp"
#include "Properties.cpp"

class GameController
{
public:
    GameController(sf::RenderWindow &window, LunarLander &lander, LunarSurface &surface, Properties &properties)
        : window_(window), lander_(lander), surface_(surface), properties_(properties) {}

    void Run()
    {
        sf::Clock clock;
        sf::Time deltaTime;
        float realDeltaTime;

        while (window_.isOpen())
        {
            deltaTime = clock.restart();
            realDeltaTime = deltaTime.asSeconds();

            HandleEvents();
            HandleInput(realDeltaTime);
            lander_.UpdatePosition(realDeltaTime, window_.getSize().x, window_.getSize().y);

            Render();
        }
    }

private:
    void HandleEvents()
    {
        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_.close();
            }
        }
    }

    void HandleInput(float realDeltaTime)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            lander_.Rotate(-std::stof(properties_.getValue("lander_rotate_speed")), realDeltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            lander_.Rotate(std::stof(properties_.getValue("lander_rotate_speed")), realDeltaTime);
        }
    }

    void Render()
    {
        window_.clear();
        lander_.Draw(window_);
        lander_.DrawAlt(window_);
        surface_.Draw(window_);
        window_.display();
    }

    sf::RenderWindow &window_;
    LunarLander &lander_;
    LunarSurface &surface_;
    Properties &properties_;
};

int main()
{
    Properties properties("config.ini");
    sf::RenderWindow window(sf::VideoMode(800, 600), "Lunar Lander");
    LunarLander lander(400, 500, 0);
    LunarSurface surface(800, 600, 20);
    GameController game(window, lander, surface, properties);
    game.Run();
}