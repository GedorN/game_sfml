#include"../Headers/Policecop.hpp"
#include<stdio.h>

Policecop::Policecop(unsigned int g, unsigned int st)
    :Enemy("./Images/coppolice.png", sf::IntRect(0, 0, 170, 200), sf::Vector2f(1500, 500), sf::Vector2f(0, 0), 50)
{
    ground = g;
    damage = 5;
    position.y= ground;
    position.x= st;
}

Policecop::~Policecop()
{
}

void Policecop::draw(sf::RenderWindow *window)
{
        window->draw(sprite);
}

int Policecop::getPower()
{
    return damage;
}

void Policecop::update(unsigned int frames)
{
    if(frames%5 == 0 )
        {
           velocity.x=-22;
           sprite.setScale(0.6,0.6);
           position.x += velocity.x;
           rect.left=(rect.left+170)%680;
           

           if(position.x<-100)
           {
                rect.left=680;
                position.x=1500;
           }
          
        }
    
       
        sprite.setTextureRect(rect);
        sprite.setPosition(position);
}


sf::Sprite* Policecop::getSprit()
{
    return &sprite;
}

sf::Vector2f Policecop::getPosition()
{
    return position;
}

void Policecop::takeDamage(int n)
{
    health-= n;
}

int Policecop::getHealth()
{
    return health;
}