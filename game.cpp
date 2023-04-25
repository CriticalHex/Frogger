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

	//third line cars moving right
	int count = 3;
	sf::Vector2f pos;
	for (int i = 0; i < count; i++) {
		pos.x = (windowSize.x / 3) * (i + 1);
		pos.y = windowSize.y - tileSize.y * 3;
		gameObjects.push_back(std::make_unique<Car>(pos, .35));
		pos.y = windowSize.y - tileSize.y * 4;
		gameObjects.push_back(std::make_unique<Car>(pos, -.4));
		pos.y = windowSize.y - tileSize.y * 5;
		gameObjects.push_back(std::make_unique<Car>(pos, .5));
		pos.y = windowSize.y - tileSize.y * 6;
		gameObjects.push_back(std::make_unique<Car>(pos, -.3));
		pos.y = windowSize.y - tileSize.y * 7;
		gameObjects.push_back(std::make_unique<Car>(pos, .3));
		pos.y = windowSize.y - tileSize.y * 9;
		gameObjects.push_back(std::make_unique<Turtle>(pos, .3));
	}

	gameObjects.push_back(std::make_unique<Player>());
};

void Game::garbageCollect() {
	std::vector<std::vector<std::unique_ptr<GameObject>>::iterator> toDelete;
	for (std::vector<std::unique_ptr<GameObject>>::iterator iter = gameObjects.begin(); iter != gameObjects.end(); iter++) {
		if ((*iter).get()->remove) {
			(*iter).release();
			toDelete.push_back(iter);
		}
	}
	for (auto& iter : toDelete) {
		gameObjects.erase(iter);
	}
}

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
		garbageCollect();
	}
}