#pragma once
#include <SFML/Graphics.hpp>
#include "EntityList.hpp"
#include "Background.hpp"

class Level
{
  protected:
    Background *background;
    EntityList *ObstaclesList;
    EntityList *EnemiesList;
    EntityList *Players;

  public:
    Level(){}
    virtual ~Level(){}

    virtual void executar(unsigned int frames) {}
    virtual sf::View* getView() {}
    virtual bool getCoalision(){}
    
};