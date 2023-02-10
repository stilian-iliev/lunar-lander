#include <SFML/Graphics.hpp>
#include "LunarLander.cpp"

class GameController
{
public:
    GameController(sf::RenderWindow &window, LunarLander &lander)
        : window_(window), lander_(lander) {}

    void Run()
    {
        float deltaTime = 1.0f / 60.0f; // Time step for simulation
        while (window_.isOpen())
        {
            HandleEvents();
            HandleInput();
            lander_.UpdatePosition(deltaTime, window_.getSize().x, window_.getSize().y);
            if (lander_.GetX() < 0 || lander_.GetX() > 800 || lander_.GetY() < 0 || lander_.GetY() > 600)
            {
                window_.close();
            }
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

    void HandleInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            lander_.Rotate(-0.01);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            lander_.Rotate(0.01);
        }
    }

    void Render()
    {
        window_.clear();
        lander_.Draw(window_);
        lander_.DrawAlt(window_);
        window_.display();
    }

    sf::RenderWindow &window_;
    LunarLander &lander_;
};