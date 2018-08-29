#include "../Headers/Level2.hpp"
#include <cmath>
#include <stdlib.h>
#include <time.h>
//#include "../Headers/GraphicEffects/Darkness.hpp"

Level2::Level2(sf::RenderWindow &w)
    : window(w), frames(0)
{
    srand(time_t(NULL));

    setUp();
    setUpObstacles();
    setUpEnemies();
}

Level2::~Level2()
{
    delete background;
    delete ObstaclesList;
    delete EnemiesList;
}

void Level2::setUp()
{
    background = new Background("./Images/l2.png", sf::Vector2f(500, 2180), sf::Vector2f(800, 800), ground);

    ObstaclesList = new EntityList();
    EnemiesList = new EntityList();

    thor = new Thor(ground);

    background->setMainPlayer(thor);
    //man = new IronMan();
    thor->change(0);
}
void Level2::setUpObstacles()
{
    int n = (rand() % 30) + 1;

    Powers::Hurricane *h;
    for (int i = 0; i < n; i++)
    {
        float x = (rand() % (550 + 41962)) - 550;
        h = new Powers::Hurricane(sf::Vector2f(x, ground));
        ObstaclesList->add(h);
    }
}

void Level2::setUpEnemies()
{
    Batman *b = new Batman(ground, 30000);
    EnemiesList->add(b);

    Policecop *p;
    Bat *bat;

    int n = (rand() % 30) + 1;
    for (int i = 0; i < n; i++)
    {
        int x = (rand() % (41962 - 550)) + 550;
        p = new Policecop(ground, x);
        EnemiesList->add(p);
    }
    n = (rand() % 30) + 1;
    for (int i = 0; i < n; i++)
    {
        int x = (rand() % (550 + 41962)) - 550;
        bat = new Bat(ground, x);
        EnemiesList->add(bat);
    }
}
void Level2::executar(unsigned int frames)
{

    EnemiesList->update(frames);
    thor->update(frames);

    ObstaclesList->getMovement();

    EnemiesList->getMovement();
    thor->getMovement();

    ObstaclesList->move();
    EnemiesList->move();

    thor->move();

    window.clear(sf::Color(200, 200, 200));

    background->setView(&window);
    window.setView(*background->getView());

    ObstaclesList->draw(&window);
    EnemiesList->draw(&window);
    thor->draw(&window);

    getCoalision();

    if (thor->getHealth() <= 0)
    {
        delete background;
        delete ObstaclesList;
        delete EnemiesList;
        printf("\level morrendo!\n");

        setUp();
        setUpEnemies();
        setUpObstacles();
    }

    EnemiesList->free();
}

sf::View *Level2::getView()
{
    return (background->getView());
}

bool Level2::getCoalision()
{
    Entity *aux = thor;
    sf::Sprite *s = aux->getSprit();
    Entity *test;
    sf::Sprite *s2;

    for (int i = 0; i < ObstaclesList->getN(); i++)
    {
        test = ObstaclesList->getEntity(i);
        s2 = test->getSprit();
        if (s2 != NULL)
            if (s->getGlobalBounds().intersects(s2->getGlobalBounds()))
            {
                thor->takeDamage(test->getPower());
                s->setColor(sf::Color::Red);

                printf("\a");

                if (s->getGlobalBounds().left < s2->getGlobalBounds().left)
                {
                    thor->change(2);
                    sf::Vector2f p = thor->getPosition();
                    p.x = s2->getPosition().x - ((s2->getPosition().x - s->getPosition().x) + (s2->getGlobalBounds().width - s2->getOrigin().x));
                    thor->setPosition(p);
                }
                else
                {
                    thor->change(1);
                    sf::Vector2f p = thor->getPosition();
                    p.x = s2->getPosition().x + s2->getGlobalBounds().width;
                    thor->setPosition(p);
                }
                return true;
            }
    }
    for (int i = 0; i < EnemiesList->getN(); i++)
    {
        test = EnemiesList->getEntity(i);
        s2 = test->getSprit();
        if (s->getGlobalBounds().intersects(s2->getGlobalBounds()))
        {

            thor->takeDamage(test->getPower());
            test->takeDamage(thor->getPower());

            printf("\a");

            if (s->getGlobalBounds().left < s2->getGlobalBounds().left)
            {
                thor->change(2);
                sf::Vector2f p = thor->getPosition();
                p.x = s2->getPosition().x - s2->getGlobalBounds().width;
                thor->setPosition(p);
            }
            else
            {
                thor->change(1);
                sf::Vector2f p = thor->getPosition();
                p.x = s2->getPosition().x + s2->getGlobalBounds().width;
                thor->setPosition(p);
            }
            return true;
        }
    }

    s->setColor(sf::Color::White);
    thor->change(0);
    return false;
}