#pragma once
#include<SFML/Graphics.hpp>
#include"Player.hpp"

class IronMan : public Player
{
    private:


    public:
    IronMan(unsigned int g);
    ~IronMan();
    void draw(sf::RenderWindow *window);
    void getMovement();
    void move();
    void update(unsigned int frames);
    sf::Vector2f getPosition();

    sf::Sprite *getSprit();
    enum class blockPatch
    {
        none = 0,
        left,
        right
    };
    blockPatch bp;
    void change(int n);
    void setPosition(sf::Vector2f p);
    void takeDamage(int d);
    sf::Vector2f getOrigin();
    int getPower();

    int getHealth();
};