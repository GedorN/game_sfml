#include "../Headers/Thor.hpp"
#include <stdio_ext.h>

Thor::Thor(unsigned int g)
    : Player("./Images/odinson.png", sf::IntRect(0, 0, 120, 100), sf::Vector2f(500, 2180), /* 0, 0, 120, 100, */ sf::Vector2f(0, 0), 1000)
{
    ground = g;
    damage = 1000;
    health = 1000;
}

Thor::~Thor()
{
    printf("\nMorri");
}

void Thor::draw(sf::RenderWindow *window)
{
    window->draw(sprite);
}

void Thor::getMovement()
{

    if (!inAnimation)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            status = Movement::jumpingAndWalkingRight;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            status = Movement::jumpingAndWalkingLeft;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
        {
            status = Movement::punching;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            status = Movement::walkingRight;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            status = Movement::walkingLeft;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            status = Movement::jumping;
        }

        else
        {
            status = Movement::stopped;
        }
    }
}

void Thor::move()
{
    if (!inAnimation)
    {
        switch (status)
        {
        case Movement::stopped:

            velocity = sf::Vector2f(0, 0);
            rect.left = 0;

            rect.width = 90;
            rect.left = 5;

            break;
        case Movement::walkingRight:

            sprite.setScale(1, 1);
            rect.width = 120;

            break;
        case Movement::walkingLeft:

            if (bp != blockPatch::left)
                rect.width = 120;
            sprite.setScale(-1, 1);

            break;

        case Movement::jumping:

            velocity.y = -20;
            inAnimation = true;
            break;
        case Movement::jumpingAndWalkingRight:

            velocity = (sf::Vector2f(5.7, -20));
            sprite.setScale(1, 1);
            inAnimation = true;

            break;

        case Movement::jumpingAndWalkingLeft:

            velocity = (sf::Vector2f(-5.7, -20));
            sprite.setScale(-1, 1);
            inAnimation = true;
            break;
        case Movement::punching:

            inAnimation = true;
            //left = 0;
            rect.left = 0;
            break;
        default:
            break;
        }
    }
}

void Thor::update(unsigned int frames)
{
    if (status == Movement::walkingLeft)
    {

        if (bp != blockPatch::left)
        {
            velocity.x = -5.7;
            position.x += velocity.x;
            bp = blockPatch::none;
        }
        if (frames % 3 == 0)
        {
            rect.left = (rect.left + 120) % 1440;
        }
    }
    else if (status == Movement::walkingRight)
    {

        if (bp != blockPatch::right)
        {
            velocity.x = 5.7;

            position.x += velocity.x;
            bp = blockPatch::none;
        }

        if (frames % 3 == 0)
        {
            rect.left = (rect.left + 120) % 1440;
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
    else if (status == Movement::jumpingAndWalkingLeft || status == Movement::jumpingAndWalkingRight)
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
        static unsigned int attackTime = 0;
        attackTime++;

        if (attackTime == 4)
        {
            rect.left = 10;
            rect.top = 120;
            rect.width = 90;
        }
        else if (attackTime == 6)
        {
            rect.top = 120;
            rect.left = 210;
            rect.width = 100;
        }
        else if (attackTime == 10)
        {
            rect.left = 390;
            rect.width = 110;
            rect.top = 120;
        }
        else if (attackTime == 13)
        {
            rect.left = 570;
            rect.height = 110;
            rect.width = 80;
            rect.top = 110;
        }
        else if (attackTime == 20)
        {
            rect.left = 750;
            rect.width = 120;

            rect.top = 110;
        }
        else if (attackTime == 24)
        {
            rect.left = 930; //damage
            rect.width = 100;
            rect.height = 130;
            rect.top = 90;
        }
        else if (attackTime == 28)
        {
            rect.left = 1110; //damage
            rect.width = 180;
        }
        else if (attackTime == 32)
        {
            rect.left = 1290;
            rect.width = 160;
        }
        else if (attackTime == 36)
        {
            rect.left = 1470;
            rect.width = 100;
        }
        else if (attackTime == 40)
        {
            rect.left = 1650;
            rect.width = 90;
        }
        else if (attackTime == 44)
        {
            inAnimation = false;
            rect.top = 0;
            rect.left = 0;
            rect.width = 120;
            rect.height = 100;
            attackTime = 0;
        }
    }
    sprite.setTextureRect(rect);
    sprite.setPosition(position);
}

sf::Vector2f Thor::getPosition()
{
    return position;
}

sf::Sprite *Thor::getSprit()
{
    return &sprite;
}

int Thor::getHealth()
{
    return health;
}
void Thor::change(int n)
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

void Thor::setPosition(sf::Vector2f p)
{
    position = p;
    sprite.setPosition(position);
}

void Thor::takeDamage(int n)
{
    if (!((rect.left == 930 || rect.left == 1110 || rect.left == 750) && rect.top == 90))
    {
        health = health - n;
        printf("\n\nVIDA: %d\a", health);
        sprite.setColor(sf::Color::Red);
    }
}

sf::Vector2f Thor::getOrigin()
{
    return sprite.getOrigin();
}

int Thor::getPower()
{

    if ((rect.left == 930 || rect.left == 1110) && rect.top == 90)
    {
        return damage;
    }

    else
    {
        return 0;
    }
}