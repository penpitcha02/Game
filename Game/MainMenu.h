#ifndef MAINMENU_H
#define MAINMENU_H

#include "Game.h"

class MainMenu:
	public Game
{
private:
	//Variables
	sf::RectangleShape background;
	sf::Font font;


	//Function
	void initVariables();
	void initbackground();
	void initFonts();
	void initKeybinds();
	void initButtons();

public:
	MainMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~MainMenu();

	//Function
	void endState();

	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
};

#endif