CP=g++
LIB=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -I.
FILES= main.cpp ./Sources/IronMan.cpp ./Headers/Obstacle.hpp ./Headers/Entity.hpp ./Headers/Graph.hpp ./Headers/Character.hpp ./Headers/Player.hpp ./Sources/Thor.cpp ./Sources/GraphicEffects/Darkness.cpp ./Sources/Background.cpp ./Sources/Powers/Hurricane.cpp ./Headers/Element.hpp ./Sources/EntityList.cpp ./Headers/Level.hpp ./Headers/Enemy.hpp ./Sources/Policecop.cpp ./Sources/Level1.cpp ./Sources/Batman.cpp ./Sources/Menu.cpp ./Sources/GameEngine.cpp ./Headers/State.hpp ./Sources/LevelList.cpp ./Sources/Level2.cpp ./Sources/Bat.cpp ./Sources/Superman.cpp

all:
	$(CP) $(FILES) $(LIB) -o exe
	./exe
clean:
	rm -rf exe *.o
