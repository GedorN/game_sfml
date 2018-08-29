#include "../Obstacle.hpp"
#include <SFML/Graphics.hpp>

namespace GraphicEffects
{
    class Darkness : public Obstacle
    {
      protected:
    unsigned int start;
    unsigned int end;

      public:
        Darkness(unsigned int LI = 0, unsigned int LS =0);
        ~Darkness();

        void draw(sf::RenderWindow *window);
        sf::Sprite* getSprit();
        sf::Vector2f getPosition();

        
    };
}
