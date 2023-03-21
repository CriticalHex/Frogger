#include"player.h"

Game::Game() {
	window.create(sf::VideoMode(1920, 1080), "Frogger", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
}

GameObject::GameObject(int x, int y, sf::Vector2f size, sf::Color color) {
	rect.setSize(size);
	rect.setFillColor(color);
	rect.setPosition(sf::Vector2f(x, y));
}

void Game::run() {

	gameObjects.push_back(std::make_unique<Player>());

	while (window.isOpen()) {
		while (window.pollEvent(gameEvent))
		{
			// Close window: exit-----------------
			if (gameEvent.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
				window.close();
			}
		}
		//UPDATE-------------------------------------------------------------
		for (std::unique_ptr<GameObject>& object : gameObjects) {
			object.get()->update(*this, 1);
		}

		//RENDER--------------------------------------------------------------
		window.clear(bgColor);

		for (std::unique_ptr<GameObject>& object : gameObjects) {
			object.get()->draw(window);
		}

		window.display();
	}
}