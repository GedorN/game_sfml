#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
class Character : public Entity
{
    protected:
    int health;
    sf::Vector2f velocity;
    enum class Movement
    {
        stopped= 0,
        walkingRight,
        jumpingAndWalkingRight,
        walkingLeft,
        jumpingAndWalkingLeft,
        jumping,
        punching
    };
    bool inAnimation;
    Movement status;


    public:
    Character(char* IMGTexture, sf::IntRect setRect, sf::Vector2f setPosition, /*int setTop, int setLeft, int setWidth, int setHeight*/ sf::Vector2f setVelocity, int setHealth)
    :Entity(IMGTexture, setRect, setPosition )/*setTop, setLeft, setWidth, setHeight)*/
    {
        velocity= setVelocity;
        health= setHealth;
        inAnimation= false;
    }
    ~Character(){}

    virtual void getMovement(){}
    virtual void move(){}
    virtual void update(unsigned int frames){}

    virtual int getHealth(){}
    virtual void sethealth(int damage) {}

    

    




};