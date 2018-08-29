#pragma once
#include <SFML/Graphics.hpp>
#include "Graph.hpp"
#include <stdio_ext.h>
class Entity : public Graph
{

  protected:
    sf::Texture texture;
    sf::IntRect rect;
    sf::Sprite sprite;
    sf::Vector2f gravity;
    int damage;
    int ground;
    int health;

    sf::Vector2f position;

  public:
  public:
    Entity(const char *IMGTexture, sf::IntRect setRect, sf::Vector2f setPosition /*int setTop, int setLeft, int setWidth, int setHeight*/)
        : Graph()
    {
        

        texture.loadFromFile(IMGTexture);
        sprite.setTexture(texture);
        rect = setRect;
        sprite.setTextureRect(rect);
        sprite.setOrigin((setRect.width / 2), (setRect.height / 2));
        sprite.setPosition(setPosition);
        position = sf::Vector2f(sprite.getPosition());
        gravity = sf::Vector2f(0, 0.83);
    }
    virtual ~Entity() {}


    virtual void draw(sf::RenderWindow *window) {}
    virtual void update(unsigned int frames) {}
    virtual void getMovement() {}
    virtual void move() {}

    virtual sf::Sprite *getSprit() {}
    virtual sf::Vector2f getPosition() {}
    virtual int d() {}
    virtual void takeDamage(int d) {}
    virtual int getHealth() {}
    virtual int getPower() {}

};
