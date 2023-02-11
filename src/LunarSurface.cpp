#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class LunarSurface
{
public:
    LunarSurface(int windowWidth, int windowHeight, int numPoints)
    {
        surfacePoints.reserve(numPoints + 1);

        surfacePoints.emplace_back(0, (float)rand() / RAND_MAX * windowHeight / 2 + windowHeight / 2);

        // Generate random points for the surface
        for (int i = 0; i < numPoints; ++i)
        {
            float x = (float)i / (numPoints - 1) * windowWidth;
            float y = (float)rand() / RAND_MAX * windowHeight / 2 + windowHeight / 2;

            if (i % 8 == 0)
            {
                y = surfacePoints[surfacePoints.size() - 1].y;
            }

            surfacePoints.emplace_back(x, y);
        }
    }

    void Draw(sf::RenderWindow &window)
    {
        for (unsigned int i = 0; i < surfacePoints.size() - 1; ++i)
        {
            sf::Vertex line[] =
                {
                    sf::Vertex(surfacePoints[i], sf::Color::White),
                    sf::Vertex(surfacePoints[i + 1], sf::Color::White)};

            window.draw(line, 2, sf::Lines);
        }
    }

private:
    std::vector<sf::Vector2f> surfacePoints;
};
