#pragma once
#include<SFML/Graphics.hpp>
#include"Character.hpp"

class Enemy: public Character
{   
    protected:

    public:
            Enemy(char* IMGTexture,sf::IntRect setRect,sf::Vector2f setPosition,sf::Vector2f setVelocity,int setHealth)
            :Character(IMGTexture,setRect,setPosition,setVelocity,setHealth)
            {}
            ~Enemy(){}

};