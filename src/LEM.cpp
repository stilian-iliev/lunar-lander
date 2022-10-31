#include "LEM.h"

LEM::LEM()
{
    this->x = 100;
    this->y = 100;
    this->shape = sf::RectangleShape(sf::Vector2f(x, y));
    this->shape.setOrigin(50.0f, 50.0f);
    this->shape.setPosition(200, 200);
}

void LEM::rotate(double a)
{
    this->a += a;
    this->shape.setRotation(45.0f);
}

void LEM::draw(sf::RenderWindow &window)
{
    window.draw(this->shape);
}
