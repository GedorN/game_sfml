#pragma once
#include <SFML/Graphics.hpp>
#include "Level.hpp"

#include "IronMan.hpp"
#include <vector>

#include "Superman.hpp"
#include "./GraphicEffects/Darkness.hpp"

class Principal;

class Level1 : public Level
{

protected:
  Principal *principal;
  sf::RenderWindow &window;
  Thor *thor;
  IronMan *man;
  sf::Clock clock;
  sf::Time time;
  unsigned int frames;
  Powers::Hurricane *h;
  int ground = 2180;

public:
  Level1(sf::RenderWindow &w);
  ~Level1();

  void executar(unsigned int frames);
  void setPrincipal(Principal *p);
  void setUp();
  void setUpObstacles();
  void setUpEnemies();

  sf::View *getView() { background->getView(); }

  bool getCoalision();
};