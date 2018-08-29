#include "../Headers/IronMan.hpp"
#include <stdio.h>
IronMan::IronMan(unsigned int g)
    : Player("./Images/stark.png", sf::IntRect(0, 0, 40, 53), sf::Vector2f(550, ground),/* 0, 0, 40, 53,*/ sf::Vector2f(0, 0), 300)
{
 
    sprite.setScale(1.3, 1.4);
    ground = g;
}
IronMan::~IronMan()
{
}

void IronMan::draw(sf::RenderWindow *window)
{
    window->draw(sprite);
}

void IronMan::getMovement()
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

void IronMan::move()
{
    if (!inAnimation)
    {
        switch (status)
        {
        case Movement::stopped:

            velocity = sf::Vector2f(0, 0);
            break;
        case Movement::walkingRight:

            velocity.x = 2.7;
             sprite.setScale(1.3, 1.4);
            break;
        case Movement::walkingLeft:

            velocity.x = -2.7;
            sprite.setScale(-1.3, 1.4);
            break;

        case Movement::jumping:

            velocity.y = -17;
            inAnimation = true;
            break;
        case Movement::jumpingAndWalkingRight:

            velocity = (sf::Vector2f(2.7, -17));
            sprite.setScale(1.3, 1.4);
            inAnimation = true;
            break;

        case Movement::jumpingAndWalkingLeft:

            velocity = (sf::Vector2f(-2.7, -17));
            sprite.setScale(-1.3, 1.4);
            inAnimation = true;
            break;
        case Movement::punching:

            inAnimation = true;
            //left = 0;
            rect.left= 0;
            break;
        default:
            break;
        }
    }
}

void IronMan::update(unsigned int frames)
{
    if (status == Movement::walkingRight || status == Movement::walkingLeft)
    {
        position.x += velocity.x;
        if (frames % 3 == 0)
        {
            rect.left = (rect.left + 40) % 320;
        }
    }
    else if (status == Movement::jumping)
    {
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
        if (frames % 2 == 0)
        {
            rect.top= 53;
        }
        if (frames % 9 == 0 && rect.left < 100)
        {
            rect.left += 50;
        }
         if (frames % 49 == 0 && rect.left == 100)
        {
            rect.left += 50;
        }
        else if (rect.left == 150 && frames % 53 == 0)
        {
                        
             rect.left = 120;
             rect.top = 0;
            inAnimation = false;
        }
    }

    sprite.setTextureRect(rect);
    sprite.setPosition(position);
}

sf::Vector2f IronMan::getPosition()
{
    return position;
}

sf::Sprite *IronMan::getSprit()
{
    return &sprite;
}

int IronMan::getHealth()
{
    return health;
}
void IronMan::change(int n)
{
    switch (n)
    {
    case 0:
        bp = blockPatch::none;
        break;
    case 1:
        bp = blockPatch::left;
        break;
    case 2:
        bp = blockPatch::right;
        break;
    default:
        break;
    }
}

void IronMan::setPosition(sf::Vector2f p)
{
    position = p;
    sprite.setPosition(position);
}

void IronMan::takeDamage(int n)
{
    if (!((rect.left == 930 || rect.left == 1110 || rect.left == 750) && rect.top == 90))
    {
        health = health - n;
        printf("\n\nVIDA: %d\a", health);
        sprite.setColor(sf::Color::Red);
    }
}

sf::Vector2f IronMan::getOrigin()
{
    return sprite.getOrigin();
}

int IronMan::getPower()
{
    return damage;
}