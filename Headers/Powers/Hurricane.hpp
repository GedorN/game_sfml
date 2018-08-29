#pragma once
#include"../Obstacle.hpp"
#include<SFML/Graphics.hpp>

namespace Powers
{
    class Hurricane : public Obstacle
    {
        protected:
        unsigned int timeInFrames;

        public:
        Hurricane(sf::Vector2f pos, unsigned int time = 0);
        virtual ~Hurricane();
        void draw(sf::RenderWindow *windows);

        sf::Sprite* getSprit();
        int getPower();


    };



}