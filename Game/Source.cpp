#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game!", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape player(sf::Vector2f(300.0f, 425.0f));
	player.setPosition(0.0f, 0.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("img/grandpa.png");
	player.setTexture(&playerTexture);

	sf::Vector2u textureSize = playerTexture.getSize();
	textureSize.x /= 5;
	textureSize.y /= 3;

	player.setTextureRect(sf::IntRect(textureSize.x * 4, textureSize.y * 2, textureSize.x, textureSize.y));

	while (window.isOpen())
	{
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

		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}