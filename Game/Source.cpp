#include <SFML/Graphics.hpp>
#include <iostream>
#include"Animation.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game!", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape player(sf::Vector2f(300.0f, 425.0f));
	player.setPosition(0.0f, 0.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("img/grandpa2.png");
	player.setTexture(&playerTexture);

	Animation animation(&playerTexture, sf::Vector2u(4, 2), 0.3f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);

		window.clear(sf::Color(150, 150, 150));
		window.draw(player);
		window.display();
	}

	return 0;
}