#pragma once
#include<SFML/Graphics.hpp>
#include"Character.hpp"

class Player: public Character
{
    protected:


    public:
    Player(char* IMGTexture, sf::IntRect setRect, sf::Vector2f setPosition,/* int setTop, int setLeft, int setWidth, int setHeight,*/ sf::Vector2f setVelocity, int setHealth)
    :Character(IMGTexture, setRect, setPosition, /*setTop, setLeft, setWidth, setHeight, */setVelocity, setHealth)
    {}
    ~Player(){}

    virtual sf::Vector2f getPosition(){}


};