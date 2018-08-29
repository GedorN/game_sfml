#include"../../Headers/Powers/Hurricane.hpp"
#include<stdio_ext.h>
using namespace Powers;


Hurricane::Hurricane(sf::Vector2f pos, unsigned int time)
:Obstacle("./Images/hurricane.png", sf::IntRect(4,0, 47, 55), pos )
{
    timeInFrames= time;
    sprite.setScale(1, 3);
    damage= 7;


}
int Hurricane::getPower()
{
    return damage;
    
}
Hurricane::~Hurricane(){printf("\nMorri"); }

void Hurricane::draw(sf::RenderWindow *window)
{
    timeInFrames++;
    if(timeInFrames % 3 ==0)
    {
        rect.left= (rect.left + 56) % 392;
        position.x+= -3;
    }
    sprite.setPosition(position);
    sprite.setTextureRect(rect);
    window->draw(sprite);
}

sf::Sprite* Hurricane::getSprit()
{
    return &sprite;
}