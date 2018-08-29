#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

class Policecop : public Enemy
{
      private:

      public:
        Policecop(unsigned int g, unsigned int st);
        ~Policecop();
        void draw(sf::RenderWindow *window);
        void update(unsigned int frames);
        
        sf::Sprite* getSprit();
        sf::Vector2f getPosition();

        int getPower();
        void takeDamage(int n);
        int getHealth();
        
};
