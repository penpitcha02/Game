#include <SFML/Graphics.hpp>
#include <iostream>
#include"Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game!", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("img/grandpa2.png");

	Player player(&playerTexture, sf::Vector2u(4, 2), 0.3f,200.0f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	bool isFullscreen = true;

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
						window.create(sf::VideoMode(1920, 1080), "Game!", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);

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

		window.clear(sf::Color(150, 150, 150));
		player.Draw(window);
		window.display();
	}

	return 0;
}