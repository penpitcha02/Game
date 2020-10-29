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

	//MainMenu
	MainMenu mainmenu(1920,1080);

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

	sf::Texture machineTexture;
	machineTexture.loadFromFile("img/machine.png");

	Machine machine(&machineTexture);

	//Tree
	sf::Texture treeanimationTexture;
	treeanimationTexture.loadFromFile("img/treeanimation.png");

	Treeanimation treeanimation(&treeanimationTexture, sf::Vector2u(4, 1), 0.25f, 500.0f);

	sf::RectangleShape tree(sf::Vector2f(960.0f, 1080.0f));
	tree.setOrigin(tree.getSize().x / 2.0f, 0);
	tree.setPosition(0.0f, 40.0f);
	sf::Texture treeTexture;
	treeTexture.loadFromFile("img/tree.png");
	tree.setTexture(&treeTexture);

	//Tree2
	sf::Texture treeanimation2Texture;
	treeanimation2Texture.loadFromFile("img/treeanimation2.png");

	Treeanimation2 treeanimation2(&treeanimation2Texture, sf::Vector2u(4, 1), 0.25f, 500.0f);

	sf::RectangleShape tree2(sf::Vector2f(960.0f, 1080.0f));
	tree2.setOrigin(tree2.getSize().x / 2.0f, 0);
	tree2.setPosition(1700.0f, 40.0f);
	sf::Texture tree2Texture;
	tree2Texture.loadFromFile("img/tree2.png");
	tree2.setTexture(&tree2Texture);

	//Tree3
	sf::Texture treeanimation3Texture;
	treeanimation3Texture.loadFromFile("img/treeanimation3.png");

	Treeanimation3 treeanimation3(&treeanimation3Texture, sf::Vector2u(4, 1), 0.25f, 500.0f);

	sf::RectangleShape tree3(sf::Vector2f(960.0f, 1080.0f));
	tree3.setOrigin(tree3.getSize().x / 2.0f, 0);
	tree3.setPosition(820.0f, 40.0f);
	sf::Texture tree3Texture;
	tree3Texture.loadFromFile("img/tree3.png");
	tree3.setTexture(&tree3Texture);

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
		treeanimation3.Update(deltaTime);

		view.setCenter(player.GetPosition());

		//////Render

		window.clear(); 

		//MainMenu
		mainmenu.Draw(window);

		//View
		window.setView(view);
		window.draw(background);

		//Tree
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			treeanimation.Draw(window);
		else
			window.draw(tree);

		//Tree2
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			treeanimation2.Draw(window);
		else
			window.draw(tree2);

		//Tree
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			treeanimation3.Draw(window);
		else
			window.draw(tree3);

		//Weapon
		sword.Draw(window);
		player.Draw(window); 
		knife.Draw(window);

		//Shop
		window.draw(shop);

		//Machine
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(machine.isMouseOver(window))
			machineanimation.Draw(window);
		}
		else
			machine.Draw(window);

		window.display();
	}

	return 0;
}
