#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "State.hpp"

class Menu {
 public:
	Menu(sf::RenderWindow &window, State::StateEngine* pState);
	~Menu();
	void lightOption();
	void draw();
	void setupOptions();
	void pause();
	void operator++();
	void operator--();
	void setGameState(State::GameState* pState);
	State::StateEngine checkOption();

 private:
	std::vector <sf::Text*> menu_options;
	sf::Font font;
	sf::RenderWindow& m_window;
	int currentOption;
	State::StateEngine* m_state;
	State::GameState* m_gameState;
};
