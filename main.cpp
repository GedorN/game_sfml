#include <SFML/Graphics.hpp>
#include<cmath>
#include "./Headers/IronMan.hpp"
#include "./Headers/Thor.hpp"
#include "./Headers/Background.hpp"
#include"./Headers/Powers/Hurricane.hpp"
#include"./Headers/EntityList.hpp"

#include"./Headers/Level1.hpp"
#include<time.h>
#include<stdlib.h>

#include"./Headers/GameEngine.hpp"

//#include "./Headers/GraphicEffects/Darkness.hpp"
//using namespace GraphicEffects;
int main()
{
    
    GameEngine *p =new GameEngine();
    delete p;
    
    
   /* sf::RenderWindow window(sf::VideoMode(1300, 900), "Test");
    unsigned int frames = 0; 
    sf::Clock clock;
    sf::Time time;
    IronMan *man= new IronMan();
    Thor *thor = new Thor();

    unsigned int i= 30;
    GraphicEffects::Darkness *dark = new GraphicEffects::Darkness(1); 
    // sf::Texture back;
    // back.loadFromFile("./Images/got.png");
    // sf::Sprite fundao;
    // fundao.setTexture(back);
    // fundao.setPosition(0,0);
    // fundao.setScale(2,2);
    //sf::View view(sf::FloatRect(30, 1300, 900,500));
    //   sf::View view(thor->position, sf::Vector2f(700, 700) );
    //back.setRepeated
    Background *back=new Background("./Images/go.png", thor->position, sf::Vector2f(800, 800));

    Powers::Hurricane *h = new Powers::Hurricane(sf::Vector2f(120, 2180));
    EntityList *list= new EntityList();
   // list->add(man);
    list->add(thor);
    //Policecop *p= new Policecop();
    //list->add(p);


    //Player la();

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        time= clock.getElapsedTime();
        frames= static_cast<unsigned int> (fmod(frames, 1.0f / time.asSeconds() ) + 1.0f);
        // printf("\n%f", 1.0f / time.asSeconds());    
        //printf("\n%u", frames);
        clock.restart().asSeconds();

       // thor->update(frames);
       // man->update(frames);
        list->update(frames);

      // thor->getMovement();
       list->getMovement();
        //man->getMovement();

       // thor->move();
        list->move();
        //man->move();
        //man->update(frames);
        
        
        
     window.clear(sf::Color(200, 200, 200));
sf::Vector2f t= thor->position;
        t.y+= -200;
        //window.draw(fundao);
        back->setView(&window, t);
        //man->draw(&window);
        //thor->draw(&window);
        list->draw(&window);
        dark->draw(&window);
        h->draw(&window);

        
        
        //  view.setCenter(t);
         //  window.setView(view);

        window.display();

        
    }
    delete man;
    delete thor;
    delete dark;
    delete back;
    delete h;
    delete list;
    //delete p;*/
}