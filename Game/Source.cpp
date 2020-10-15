#include <SFML/Graphics.hpp>
#include <iostream>
#include"Player.h"

int main()
{
	//Window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game!", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);

	//Fullscreen
	bool isFullscreen = true;

	//View
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1920.0f, 1080.0f));
	
	//grandpa
	sf::Texture playerTexture;
	playerTexture.loadFromFile("img/grandpa2.png");

	Player player(&playerTexture, sf::Vector2u(4, 2), 0.3f,500.0f);
	 
	float deltaTime = 0.0f;
	sf::Clock clock;

	//background
	sf::RectangleShape background(sf::Vector2f(5760.0f, 1080.0f));
	background.setPosition(-960.0f, 40.0f);
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("img/background3.png");
	background.setTexture(&backgroundTexture);

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::KeyReleased:
				switch (evnt.key.code)
				{
				case sf::Keyboard::Return:
					if (true == isFullscreen)
					{
						window.create(sf::VideoMode(1920, 1080), "Game!", sf::Style::Close | sf::Style::Titlebar | sf::Style::Default);

						isFullscreen = false;
					}
					else
					{
						window.create(sf::VideoMode(1920, 1080), "Game!", sf::Style::Fullscreen);

						isFullscreen = true;
					}

					break;

				}

				break;

			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		player.Update(deltaTime);
		view.setCenter(player.GetPosition());

		//Render
		window.clear();
		window.setView(view);
		window.draw(background);
		player.Draw(window);
		window.display();
	}

	return 0;
}