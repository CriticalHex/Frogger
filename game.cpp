#include"player.h"
#include"enemy.h"

Game::Game() {
	window.create(sf::VideoMode(1920, 1080), "Frogger", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
}

GameObject::GameObject(int x, int y, sf::Vector2f size, sf::Color color, std::string type) {
	rect.setSize(size);
	rect.setFillColor(color);
	rect.setPosition(sf::Vector2f(x, y));
	typeName = type;
}


void GameObject::draw(sf::RenderWindow& window) {
	window.draw(rect);
};

void Game::initialize() {
	//first line is info
	//second line player spawn
	gameObjects.push_back(std::make_unique<Player>());
	//third line cars moving left
	for (int i = 0; i < 3; i++) {
		gameObjects.push_back(std::make_unique<Car>(sf::Vector2f(tileSize.x * (i + 1), windowSize.y - tileSize.y * 3), .5));
	}

};

void Game::run() {

	initialize();

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
		delta = clock.getElapsedTime();
		clock.restart();
		for (std::unique_ptr<GameObject>& object : gameObjects) {
			object.get()->update(gameObjects, delta.asMilliseconds());
		}

		//RENDER--------------------------------------------------------------
		window.clear(bgColor);

		for (std::unique_ptr<GameObject>& object : gameObjects) {
			object.get()->draw(window);
		}

		window.display();
	}
}