#ifndef GAME_H
#define GAME_H


#include<iostream>

#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>


#include"Player.h"

class Game
{
private:
	//Variable
	sf::RenderWindow *window;
	sf::Event sfEvent;

	//Initialization
	void initWindow();

public:
	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Functions
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif

