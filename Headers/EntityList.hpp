#pragma once
#include<SFML/Graphics.hpp>
#include"Element.hpp"
#include"Entity.hpp"

#include"Character.hpp"
#include"Policecop.hpp""
#include "Bat.hpp"
#include "Batman.hpp"
#include "../Headers/Thor.hpp"
#include "./Powers/Hurricane.hpp"
#include "./Obstacle.hpp"
#include "./Superman.hpp"


//#include"Level.hpp"

class Level1;
class EntityList
{
    protected:
    unsigned int n;
    Element<Entity> *first;
    Element<Entity> *current;

   // Level *level;

    public:
    EntityList();
    ~EntityList();

    void add(Entity  *info);
    void free();

    void update(unsigned int frame);
    void getMovement();
    void move();
    void draw(sf::RenderWindow *window);

    Entity* getEntity(int x);

    int getN();

};