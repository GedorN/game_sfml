#include "../Headers/Background.hpp"
#include<cstdlib>

Background::Background(char *IMG, sf::Vector2f npos, sf::Vector2f nsize, int g)
    : Graph()
{
    texture.loadFromFile(IMG);
    texture.setRepeated(true);
    background.setTextureRect(sf::IntRect(0, 0, 14000, 1600));
    background.setTexture(texture);

    background.setPosition(-10, 0);
    background.setScale(3, 2.5);
    size = nsize;
    pos= npos;
    view.setSize(size);
    view.setCenter(pos);
    ground = g;
}

Background::~Background() {}

void Background::setView(sf::RenderWindow *window)
{
    sf::Vector2f position = player->getPosition();
    if (position.x + size.x > 1230)
    {
        pos.x= player->getPosition().x;
      //  printf("\n!!CEITA");
        view.setCenter(pos);
    }
    
    pos.y=position.y - 200;
    while ( pos.y + (size.y /2) > ground + 120 )
    {
       pos.y+= -1;
   }
    view.setCenter(pos);
    window->draw(background);
    //window->setView(view);
     
}

void Background::setMainPlayer(Player *p){ player = p;}

