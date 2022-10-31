#include "Game.h"

Game::Game()
{
    this->window = new sf::RenderWindow(sf::VideoMode(512, 512), "Lunar lander", sf::Style::Default);

    this->lem = LEM();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->lem.rotate(0);
        render();
    }
}

void Game::render()
{
    printf("here");
    window->clear();
    this->lem.draw(*this->window);
    window->display();
}