#include "../../Headers/GraphicEffects/Darkness.hpp"
#include <cstdio>
using namespace GraphicEffects;

Darkness::Darkness(unsigned int LI, unsigned int LF)
    : Obstacle("", sf::IntRect(0, 0, 0, 0), sf::Vector2f(0, 0))
{
    start = LI;
    end = LF;
  
}
Darkness::~Darkness() {}

void Darkness::draw(sf::RenderWindow *window)
{
   static unsigned int period;
   period++;

    if (period >= start && period <= end)
    {
        printf("\nPeriode: %u", period);

        window->clear(sf::Color::Black);
        window->display();
    }
}

sf::Sprite *Darkness::getSprit() { return NULL; }

sf::Vector2f Darkness::getPosition() {}

