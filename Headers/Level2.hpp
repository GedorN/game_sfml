#pragma once
#include<SFML/Graphics.hpp>
#include"Level.hpp"
#include"Thor.hpp"
#include"./Powers/Hurricane.hpp"
#include"Obstacle.hpp"
#include"IronMan.hpp"

class Principal;

class Level2 : public Level
{
    protected:
    Principal *principal;
    sf::RenderWindow &window;
    Thor *thor;
    sf::Clock clock;
    sf::Time time;
    unsigned int frames;
     int ground = 2180;

    public:
    Level2(sf::RenderWindow &w);
    ~Level2();

    void executar(unsigned int frames);
    void setPrincipal(Principal *p);
    void setUp();
    void setUpObstacles();
    void setUpEnemies();

    sf::View* getView();

    void makeLevel();

    bool getCoalision();
  


};