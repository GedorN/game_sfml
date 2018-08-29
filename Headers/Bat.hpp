#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

class Bat : public Enemy
{
      private:
        int start;
      public:
        Bat(unsigned int g, unsigned int place);
        ~Bat();
        void draw(sf::RenderWindow *window);
        void update(unsigned int frames);

        sf::Sprite* getSprit();
        sf::Vector2f getPosition();
        int getPower();
        


};