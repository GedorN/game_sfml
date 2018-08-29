#pragma once
#include"Graph.hpp" 
#include<SFML/Graphics.hpp>
#include"Player.hpp"

class Background : public Graph
{
    private:
    sf::Texture texture;
    sf::Sprite background;
    sf::Vector2f pos;
    sf::Vector2f size;
    sf::View view;
    Player *player;
     int ground;
    
    public:
    Background( char *IMG,sf::Vector2f npos, sf::Vector2f nsize, int g);
    ~Background();

    void setView(sf::RenderWindow *window);
    sf::View* getView(){ return &view; }

    void setMainPlayer(Player *p);
};