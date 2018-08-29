#pragma once
#include<SFML/Graphics.hpp>
#include"Entity.hpp"


class Obstacle : public Entity
{


    public:
    Obstacle(const char* IMGTexture, sf::IntRect setRect, sf::Vector2f setPosition)
    :Entity(IMGTexture, setRect, setPosition)
    {
    }
    virtual ~Obstacle(){}

    virtual void draw(){}
};