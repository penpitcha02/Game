#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if(!font.loadFromFile("arial.ttf")){}

	//Play
	mainMenu[0].setFont(font);
	mainMenu[0].setColor(sf::Color::Blue);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(sf::Vector2f(width / 2 - 50, height / (Max_main_menu + 1)));

	//Score
	mainMenu[0].setFont(font);
	mainMenu[0].setColor(sf::Color::White);
	mainMenu[0].setString("Score");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(sf::Vector2f(width / 2 - 50, height / (Max_main_menu + 1) * 2));

	//Quit
	mainMenu[0].setFont(font);
	mainMenu[0].setColor(sf::Color::White);
	mainMenu[0].setString("Quit");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(sf::Vector2f(width / 2 - 50, height / (Max_main_menu + 1) * 3));

	mainMenuSelected = 0;

}

MainMenu::~MainMenu()
{

}

//Draw MainMenu
void MainMenu::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainMenu[i]);
	}
}

//move up
void MainMenu::moveUp()
{
	if(mainMenuSelected - 1 <= -1)
	{
		mainMenu[mainMenuSelected].setColor(sf::Color::White);

		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}
		mainMenu[mainMenuSelected].setColor(sf::Color::Blue);
	}
}

//move down
void MainMenu::moveDown()
{
	if (mainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[mainMenuSelected].setColor(sf::Color::White);

		mainMenuSelected++;
		if (mainMenuSelected == 3)
		{
			mainMenuSelected = 0;
		}
		mainMenu[mainMenuSelected].setColor(sf::Color::Blue);
	}
}
