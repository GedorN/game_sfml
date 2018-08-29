#pragma once
#include<SFML/Graphics.hpp>
#include"Enemy.hpp"

class Batman: public Enemy
{
    private:
            

    public:
            Batman(unsigned int g, unsigned int st);
            ~Batman();
            void draw(sf::RenderWindow *window);
            void getMovement();
            void move();
            void update(unsigned int frames);

            sf::Sprite *getSprit();
            sf::Vector2f getPosition();
};