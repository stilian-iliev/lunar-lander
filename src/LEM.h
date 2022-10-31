#include <SFML/Graphics.hpp>

class LEM
{
private:
    int x;
    int y;
    int xv;
    int yv;
    int a;
    sf::RectangleShape shape;

public:
    LEM();
    void rotate(double a);
    void draw(sf::RenderWindow &window);
};
