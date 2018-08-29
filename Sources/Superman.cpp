#include"../Headers/Superman.hpp"
#include<stdio.h>

Superman::Superman(unsigned int g, unsigned int st)
        :Enemy("./Images/superpunch.png",sf::IntRect(0,0,110,95),sf::Vector2f(400,500),sf::Vector2f(0,0),200)
{
    ground= g;
    position.y= ground;
    position.x= st;
}

Superman::~Superman()
{
}

void Superman::draw(sf::RenderWindow *window)
{
    window->draw(sprite);
}

void Superman::getMovement()
{
    if(!inAnimation)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            status = Movement::jumpingAndWalkingRight;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            status = Movement::jumpingAndWalkingLeft;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            status = Movement::punching;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            status = Movement::walkingRight;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            status = Movement::walkingLeft;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            status = Movement::jumping;
        }
        else
        {
            status = Movement::stopped;
        }
    }
}

void Superman::move()
{
    if(!inAnimation)
    {
        switch(status)
        {
            case Movement::stopped:
                velocity = sf::Vector2f(0,0);
                break;

            case Movement::walkingRight:
                velocity.x = 6;
                sprite.setScale(1,1);
                break;

            case Movement::walkingLeft:
                velocity.x = -6;
                sprite.setScale(-1,1);
                break;
            
            case Movement::jumping:
                velocity.y = -17;
                inAnimation = true;
                break;

            case Movement::jumpingAndWalkingRight:
                velocity = (sf::Vector2f(6,-17));
                sprite.setScale(1,1);
                inAnimation = true;
                break;

            case Movement::jumpingAndWalkingLeft:
                velocity = (sf::Vector2f(-6,-17));
                sprite.setScale(-1,1);
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

void Superman::update(unsigned int frames)
{
    if(status == Movement::walkingRight || status == Movement::walkingLeft)
    {
        position.x += velocity.x;

        if(frames % 7 ==0)
        {
            rect.left = (rect.left +110) % 550;
        }
    }
    else if(status == Movement::jumping)
    {
        position.y += velocity.y;
        velocity += gravity;

        if(position.y >= ground)
        {
            position.y = ground;
            inAnimation = false;
        }

    }
    else if(status == Movement::jumpingAndWalkingRight || status == Movement::jumpingAndWalkingLeft)
    {
        position += velocity;
        velocity += gravity;

        if(position.y >= ground)
        {
            position.y = ground;
            inAnimation = false;
        }
    }
    else if(status == Movement::punching)
    {
                if(frames % 9 == 0 && rect.left<110)
                {       rect.top=100;
                        rect.left=(rect.left+110);
                }
                if(frames %29 == 0 && rect.left==110)
                {
                        rect.left =(rect.left+110);
                }
                else if(rect.left==220 && frames % 39 ==0)
                {
                        rect.top=0;
                        rect.left=550;
                        inAnimation=false;
                        
                }
    }

    sprite.setTextureRect(rect);
    sprite.setPosition(position);
}


sf::Sprite* Superman::getSprit()
{
    return &sprite;
}


sf::Vector2f Superman::getPosition()
{
    return position;
}