#include "../Headers/Batman.hpp"
#include <stdio.h>

Batman::Batman(unsigned int g, unsigned int st)
    : Enemy("./Images/batsocoarrumado.png", sf::IntRect(0, 0, 90, 95), sf::Vector2f(500, 2180), sf::Vector2f(0, 0), 70)
{
        ground = g;
        position.x = st;
}
Batman::~Batman()
{
}

void Batman::draw(sf::RenderWindow *window)
{
        window->draw(sprite);
}

void Batman::getMovement()

{
        if (!inAnimation)
        {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                        status = Movement::jumpingAndWalkingRight;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                        status = Movement::jumpingAndWalkingLeft;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                        status = Movement::punching;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                        status = Movement::walkingRight;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                        status = Movement::walkingLeft;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                        status = Movement::jumping;
                }
                else
                {
                        status = Movement::stopped;
                }
        }
}

void Batman::move()
{
        if (!inAnimation)
        {
                switch (status)
                {
                case Movement::stopped:

                        velocity = sf::Vector2f(0, 0);

                        break;

                case Movement::walkingRight:

                        velocity.x = 4.7;
                        sprite.setScale(1, 1);
                        break;

                case Movement::walkingLeft:

                        velocity.x = -4.7;
                        sprite.setScale(-1, 1);

                        break;

                case Movement::jumping:

                        velocity.y = -12;
                        inAnimation = true;

                        break;

                case Movement::jumpingAndWalkingRight:

                        velocity = (sf::Vector2f(4.7, -12));
                        sprite.setScale(1, 1);

                        inAnimation = true;
                        break;

                case Movement::jumpingAndWalkingLeft:

                        velocity = (sf::Vector2f(-4.7, -12));
                        sprite.setScale(-1, 1);

                        inAnimation = true;
                        break;

                case Movement::punching:

                        inAnimation = true;
                        rect.left = 0;

                        break;

                default:

                        break;
                }
        }
}

void Batman::update(unsigned int frames)
{

        if (status == Movement::walkingRight || status == Movement::walkingLeft)
        {
                rect.top = 0;
                position.x += velocity.x;

                if (frames % 6 == 0)
                {
                        rect.left = (rect.left + 90) % 360;
                }
        }
        else if (status == Movement::jumping)
        {
                rect.top = 0;
                position.y += velocity.y;
                velocity += gravity;

                if (position.y >= ground)
                {
                        position.y = ground;
                        inAnimation = false;
                }
        }
        else if (status == Movement::jumpingAndWalkingRight || status == Movement::jumpingAndWalkingLeft)
        {
                rect.top = 0;
                position += velocity;
                velocity += gravity;

                if (position.y >= ground)
                {
                        position.y = ground;
                        inAnimation = false;
                }
        }
        else if (status == Movement::punching)
        {
                rect.top = 100;

                if (frames % 9 == 0 && rect.left < 90)
                {
                        rect.left = (rect.left + 90);
                }
                if (frames % 39 == 0 && rect.left == 90)
                {
                        rect.left = (rect.left + 90);
                }
                else if (rect.left == 180 && frames % 49 == 0)
                {
                        rect.left = 90;
                        rect.top = 0;
                        inAnimation = false;
                }
        }

        sprite.setTextureRect(rect);
        sprite.setPosition(position);
}

sf::Sprite *Batman::getSprit()
{
        return &sprite;
}

sf::Vector2f Batman::getPosition()
{
        return position;
}