#pragma once
#include<SFML/Graphics.hpp>
#include"Enemy.hpp"

class Superman: public Enemy
{
    private:
    
    public:
            Superman(unsigned int g, unsigned int st);
            ~Superman();
            void draw(sf::RenderWindow *window);
            void getMovement();
            void move();
            void update(unsigned int frames);

            sf::Sprite* getSprit();
            sf::Vector2f getPosition();
};