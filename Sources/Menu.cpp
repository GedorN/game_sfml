#include "./Headers/Menu.hpp"
#include <cstdio>

Menu::Menu(sf::RenderWindow &window, State::StateEngine* pState): m_window(window) {
	font.loadFromFile("./Images/Avengers.ttf");
	menu_options.push_back(new sf::Text("Iniciar Jogo", font)); // 0
	menu_options.push_back(new sf::Text("Sair do Jogo", font)); // 1
	menu_options.push_back(new sf::Text("Selecionar level", font)); // 2
	menu_options.push_back(new sf::Text("Salvar Score", font)); // 3
	menu_options.push_back(new sf::Text("Continuar Jogo", font)); // 4
	menu_options.push_back(new sf::Text("Level 1", font)); // 5
	menu_options.push_back(new sf::Text("Level 2", font)); // 6

	currentOption = 0;

	setupOptions();
	m_state = pState;
	m_gameState = NULL;
}

Menu::~Menu() {
	m_state = NULL;
	m_gameState = NULL;
}

void Menu::setGameState(State::GameState* pState) {
	m_gameState = pState;
}

State::StateEngine Menu::checkOption() {
	switch (currentOption) {
	case 0:
		return State::StateEngine::Playing;
		break;

	case 1:
		return State::StateEngine::Quit;
		break;

	case 2:
		currentOption = 5;
		lightOption();
		return State::StateEngine::LevelSelect;
		break;

	case 3:
		return State::StateEngine::SaveGame;
		break;

	case 4:
		return State::StateEngine::Playing;
		break;

	case 5:
		*m_gameState = State::GameState::Level1;
		return State::StateEngine::Playing;
		break;

	case 6:
		*m_gameState = State::GameState::Level2;
		return State::StateEngine::Playing;
		break;

	default:
		return State::StateEngine::Pause;
		break;
	}
}

void Menu::setupOptions() {

	for(int i = 0; i < static_cast<int>(menu_options.size()); i++) {
		if(i == currentOption) {
			menu_options[i]->setFillColor(sf::Color::Red);
		} else {
			menu_options[i]->setFillColor(sf::Color::White);
		}
		menu_options[i]->setOrigin(menu_options[i]->getGlobalBounds().width / 2, 0);
		menu_options[i]->setPosition( m_window.getSize().x / 2, (i + 3) * 50);
	}
}

void Menu::operator++() {
	if(*m_state == State::StateEngine::Intro) {
		currentOption = (currentOption + 1) % 3;
	} else if(*m_state == State::StateEngine::Pause) {
		currentOption = (currentOption + 1) % 5;
		if(currentOption < 1)
			currentOption = 1;
	} else if(*m_state == State::StateEngine::LevelSelect) {
		currentOption = (currentOption + 1) % 7;
		if(currentOption == 0) {
			currentOption = 5;
		}
	}
	lightOption();
}

void Menu::operator--()  {
	if(*m_state == State::StateEngine::Intro) {
		currentOption--;
		if(currentOption == -1) {
			currentOption = 2;
		}
	} else if(*m_state == State::StateEngine::Pause) {
		currentOption--;
		if(currentOption == 0) {
			currentOption = 4;
		}
	}

	else if(*m_state == State::StateEngine::LevelSelect) {
		currentOption--;
		if(currentOption == 4) {
			currentOption = 6;
		}
	}
	lightOption();
}

void Menu::lightOption() {
	for(int i = 0; i < static_cast<int>(menu_options.size()); i++) {
		if(i == currentOption) {
			menu_options[i]->setFillColor(sf::Color::Red);
		} else {
			menu_options[i]->setFillColor(sf::Color::White);

		}
	}
}

void Menu::pause() {
	currentOption = 1;
	lightOption();
}

void Menu::draw() {

	if(*m_state == State::StateEngine::Intro) {
		for(int i = 0; i < 3; i++) {
			m_window.draw(*menu_options[i]);
		}
	} else if(*m_state == State::StateEngine::Pause) {
		for(int i = 1; i < 5; i++) {
			m_window.draw(*menu_options[i]);
		}
	} else if(*m_state == State::StateEngine::LevelSelect) {
		for(int i = 5; i < 7; i++) {
			m_window.draw(*menu_options[i]);
		}
	}
}
