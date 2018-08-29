#include"../Headers/Bat.hpp"
#include<stdio.h>

Bat::Bat(unsigned int g, unsigned int place)
        :Enemy("./Images/batalterado.png",sf::IntRect(0,0,80,50),sf::Vector2f(500,2100),sf::Vector2f(0,0),40)
{
    ground= g;
    damage= 3;
    start= place;
    position.x= place;

}

Bat::~Bat()
{
}

void Bat::draw(sf::RenderWindow *window)
{
    window->draw(sprite);
}

void Bat::update(unsigned int frames)
{
            
    if(frames%5 == 0 )
        {
           velocity.x=-28;
           sprite.setScale(-1,1);
           position.x += velocity.x;
           rect.left=(rect.left+80)%480;
        }
          
           if(position.x<-100)
           {
                rect.left=480;
                position.x=start;
           }
          
        
    
       
        sprite.setTextureRect(rect);
        sprite.setPosition(position);
}

sf::Sprite* Bat::getSprit()
{
    return &sprite;
}

sf::Vector2f Bat::getPosition()
{
    return position;
}


int Bat::getPower()
{
    return damage;
}