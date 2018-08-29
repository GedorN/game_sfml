#pragma once
#include <SFML/Graphics.hpp>


namespace State {
enum class StateEngine {
	Intro = 0,
	Pause,
	Playing,
	Quit,
	SaveGame,
	LevelSelect
};

enum class GameState {
	Level1,
	Level2
};
}
