#include <SFML/Graphics.hpp>
#include <cmath>

class LunarLander
{
public:
    LunarLander(float x, float y, float angle)
        : x_(x), y_(y), angle_(angle), velocity_x_(0), velocity_y_(0) {}

    void Rotate(float delta, float deltaTime) { angle_ += delta * deltaTime; }
    void UpdatePosition(double delta_time, int window_width, int window_height)
    {
        velocity_y_ += 9.8 * delta_time;
        // ... code for updating velocity, angle, and fuel ...

        x_ += velocity_x_ * delta_time;
        y_ += velocity_y_ * delta_time;

        // Check if the lunar lander has gone beyond the boundaries of the window
        if (x_ < 0)
        {
            x_ = 0;
            velocity_x_ = 0;
        }
        else if (x_ > window_width)
        {
            x_ = window_width;
            velocity_x_ = 0;
        }
        if (y_ < 0)
        {
            y_ = window_height;
            velocity_y_ = 0;
        }
        else if (y_ > window_height)
        {
            y_ = 0;
            velocity_y_ = 0;
        }
    }

    // bool CheckCollision(const LunarSurface &surface)
    // {
    //     for (unsigned int i = 0; i < surface.surfacePoints.size() - 1; ++i)
    //     {
    //         sf::Vector2f surfaceA = surface.surfacePoints[i];
    //         sf::Vector2f surfaceB = surface.surfacePoints[i + 1];
    //         float slope = (surfaceB.y - surfaceA.y) / (surfaceB.x - surfaceA.x);
    //         float yIntercept = surfaceA.y - slope * surfaceA.x;

    //         float distance = abs(slope * position.x - position.y + yIntercept) / sqrt(pow(slope, 2) + 1);
    //         if (distance < landerWidth / 2 && (position.x >= surfaceA.x && position.x <= surfaceB.x))
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    float GetX() const { return x_; }
    float GetY() const { return y_; }
    float GetAngle() const { return angle_; }

    void Draw(sf::RenderWindow &window)
    {
        sf::ConvexShape triangle;
        triangle.setPointCount(3);
        triangle.setPoint(0, sf::Vector2f(0, 0));
        triangle.setPoint(1, sf::Vector2f(-10, 20));
        triangle.setPoint(2, sf::Vector2f(10, 20));
        triangle.setFillColor(sf::Color::White);
        triangle.setPosition(x_, y_);
        triangle.setRotation(angle_ * 180 / M_PI);
        window.draw(triangle);
    }
    void DrawAlt(sf::RenderWindow &window)
    {
        sf::Font font;

        font.loadFromFile("Midspicy Regular.ttf");
        // Display the current x and y velocity
        sf::Text x_velocity_text;
        x_velocity_text.setFont(font);
        x_velocity_text.setString("X Velocity: " + std::to_string(velocity_x_));
        x_velocity_text.setCharacterSize(24);
        x_velocity_text.setFillColor(sf::Color::White);
        x_velocity_text.setPosition(10, 10);

        sf::Text y_velocity_text;
        y_velocity_text.setFont(font);
        y_velocity_text.setString("Y Velocity: " + std::to_string(velocity_y_));
        y_velocity_text.setCharacterSize(24);
        y_velocity_text.setFillColor(sf::Color::White);
        y_velocity_text.setPosition(10, 0);

        window.draw(x_velocity_text);
        window.draw(y_velocity_text);
    }

private:
    float x_, y_;
    float angle_;
    float velocity_x_, velocity_y_;
};