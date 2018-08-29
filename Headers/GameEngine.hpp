#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Menu.hpp"
#include "Level1.hpp"
#include "Level2.hpp"
#include "LevelList.hpp"
 
class GameEngine {
 public:
	GameEngine();
	~GameEngine();
	void loop();
	void eventLoop();
	void StateManager();

 protected:

 private:
	unsigned int FPS;
	 sf::Clock clock;
    sf::Time time;
	sf::RenderWindow window;
	State::StateEngine m_state;
	Menu menu;
	Level1 *gam;
	Level2 *ga;
	Level *game;
	LevelList *lista;
	sf::View* pView;
	State::GameState g;
};
