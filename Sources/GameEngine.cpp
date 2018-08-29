#include "../Headers/GameEngine.hpp"
#include <cstdio>
#include <cmath>

GameEngine::GameEngine() : window(sf::VideoMode::getDesktopMode(), "Avengers Vs Justice League", sf::Style::Fullscreen, sf::ContextSettings(0, 0, 6)), g(State::GameState::Level1),

						   m_state(State::StateEngine::Intro),
						   menu(window, &m_state)
//game(window)
{
	menu.setGameState(&g);
	window.setFramerateLimit(60);
	lista = new LevelList();
	gam = new Level1(window);
	ga = new Level2(window);
	lista->add(gam);
	lista->add(ga);
	game = lista->getCurrentLevel(1);
	//game = new Level1(window);

	window.setKeyRepeatEnabled(false);
	FPS = 1;
	pView = game->getView();
	loop();
}

GameEngine::~GameEngine()
{
	pView = NULL;
	delete gam;
	//delete game;
}

void GameEngine::loop()
{
	while (window.isOpen())
	{
		eventLoop();
		window.clear();
		StateManager();
		window.display();
		time = clock.getElapsedTime();
		FPS = static_cast<unsigned int>(fmod(FPS, 1.0f / time.asSeconds()) + 1.0f);
		//     // printf("\n%f", 1.0f / time.asSeconds());
		//     //printf("\n%u", frames);
		clock.restart().asSeconds();
		//FPS = (FPS % 60) + 1;
	}
}

void GameEngine::StateManager()
{
	switch (m_state)
	{
	case State::StateEngine::Intro:
		printf("Intro\n");
		menu.draw();
		break;

	case State::StateEngine::Pause:
		printf("Pause\n");
		menu.draw();
		break;

	case State::StateEngine::Playing:

		switch (g)
		{
		case State::GameState::Level1: /* constant-expression */
			game = lista->getCurrentLevel(1);
			game->executar(FPS);

			break;
		case State::GameState::Level2:
			printf("\nVAi entrear\n");
			game = lista->getCurrentLevel(2);

			game->executar(FPS);
			printf("estado dois\n");

			break;

		default:
			game->executar(FPS);
			break;
		}
		// printf("Jogando\n");
		// game.executar(FPS);
		break;

	case State::StateEngine::Quit:
		printf("Sair\n");
		window.close();
		break;

	case State::StateEngine::SaveGame:
		printf("Salvar Jogo\n");
		/*
		  Nessa parte, devemos pedir para a classe Game, retornar o score do personagem
		  e o nome, para então utilizar de persistencia de objetos e salvar o jogo.
		*/
		break;

	case State::StateEngine::LevelSelect:
		menu.draw();
		printf("Selecionar Level\n");

		break;

	default:
		break;
	}
}

void GameEngine::eventLoop()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		int k = -1;
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				window.close();
				break;

			case sf::Keyboard::P:
				m_state = State::StateEngine::Pause;
				window.setView(window.getDefaultView());
				k = 0;
				break;

			case sf::Keyboard::Down:
				k = 1;
				break;

			case sf::Keyboard::Up:
				k = 2;
				break;

			case sf::Keyboard::Return:
				k = 3;
				break;

			default:
				break;
			}
			break;

		default:
			break;
		}
		if (m_state == State::StateEngine::Pause || m_state == State::StateEngine::Intro || m_state == State::StateEngine::LevelSelect)
		{
			switch (k)
			{
			case 0:
				menu.pause();
				break;
			case 1:
				++menu;
				break;

			case 2:
				--menu;
				break;

			case 3:
				m_state = menu.checkOption();
				break;

			default:
				break;
			}
		}
	}
}
