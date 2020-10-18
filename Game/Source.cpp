#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
	//Window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game!", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);

	//Fullscreen
	bool isFullscreen = true;
	
	//DeltaTime
	float deltaTime = 0.0f;
	sf::Clock clock;

	//View
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1920.0f, 1080.0f));
	
	//Grandpa
	sf::Texture playerTexture;
	playerTexture.loadFromFile("img/grandpa2.png");

	Player player(&playerTexture, sf::Vector2u(4, 2), 0.3f,500.0f);
	 
	
	//Knife
	sf::Texture knifeTexture;
	knifeTexture.loadFromFile("img/knife2.png");

	Knife knife(&knifeTexture, sf::Vector2u(4, 2), 0.3f, 500.0f);

	//Sword
	sf::Texture swordTexture;
	swordTexture.loadFromFile("img/sword.png");

	Sword sword(&swordTexture, sf::Vector2u(4, 2), 0.3f, 500.0f);


	//Machine
	sf::Texture machineanimationTexture;
	machineanimationTexture.loadFromFile("img/machineanimation.png");

	Machineanimation machineanimation(&machineanimationTexture, sf::Vector2u(4, 2), 0.3f, 500.0f);

	sf::RectangleShape machine(sf::Vector2f(375.0f, 531.25f));
	machine.setOrigin(machine.getSize().x / 2.0f, 0);
	machine.setPosition(2740.0f, 440.0f);
	sf::Texture machineTexture;
	machineTexture.loadFromFile("img/machine.png");
	machine.setTexture(&machineTexture);

	//Tree1
	sf::Texture treeanimationTexture;
	treeanimationTexture.loadFromFile("img/treeanimation.png");

	Treeanimation treeanimation(&treeanimationTexture, sf::Vector2u(4, 1), 0.25f, 500.0f);

	//Tree2
	sf::Texture treeanimation2Texture;
	treeanimation2Texture.loadFromFile("img/treeanimation2.png");

	Treeanimation2 treeanimation2(&treeanimation2Texture, sf::Vector2u(4, 1), 0.25f, 500.0f);

	//Shop
	sf::RectangleShape shop(sf::Vector2f(5760.0f, 1080.0f));
	shop.setPosition(-960.0f, 40.0f);
	sf::Texture shopTexture;
	shopTexture.loadFromFile("img/shop.png");
	shop.setTexture(&shopTexture);

	//Background
	sf::RectangleShape background(sf::Vector2f(5760.0f, 1080.0f));
	background.setPosition(-960.0f, 40.0f);
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("img/background4.png");
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
		knife.Update(deltaTime);
		sword.Update(deltaTime);
		machineanimation.Update(deltaTime);
		treeanimation.Update(deltaTime);
		treeanimation2.Update(deltaTime);
		view.setCenter(player.GetPosition());

		//Render
		window.clear(); 

		window.setView(view);
		window.draw(background);

		treeanimation.Draw(window);
		treeanimation2.Draw(window);

		sword.Draw(window);
		player.Draw(window); 
		knife.Draw(window);

		window.draw(shop);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
			machineanimation.Draw(window);
		else
			window.draw(machine);

		window.display();
	}

	return 0;
}