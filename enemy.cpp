#include"enemy.h"

void Car::update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta) {
	move(delta);
	playerCollide(gameObjects);
}

void Car::move(float delta) {
	if (speed < 0) { //moving left
		if (rect.getPosition().x + tileSize.x <= 0) {
			rect.move(sf::Vector2f(windowSize.x + tileSize.x, 0));
		}
	}
	else if (speed > 0) { //moving right
		if (rect.getPosition().x >= windowSize.x) {
			rect.move(sf::Vector2f(-windowSize.x-tileSize.x, 0));
		}
	}
	rect.move(sf::Vector2f(speed * delta, 0));
}

void Car::playerCollide(std::vector<std::unique_ptr<GameObject>>& gameObjects) {
	for (std::unique_ptr<GameObject>& object : gameObjects) {
		if (object.get()->typeName == "Player") {
			Player* player = (Player*)object.get();
			if (rect.getGlobalBounds().intersects(player->rect.getGlobalBounds())) {
				//gameover
				object.get()->rect.setPosition(sf::Vector2f(tileSize.x * (windowSize.x / (tileSize.x * 2)),
					windowSize.y - tileSize.x));
			}
		}
	}
}


void Turtle::update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta) {
	timeElapsed = timer.getElapsedTime();
	float seconds = timeElapsed.asSeconds() - timeOffset;
	switch (state) {
	case 0:
		if (seconds > 3) {
			state++;
			timer.restart();
			rect.setFillColor(sf::Color::Yellow);
		}
		break;
	case 1:
		if (seconds > 1) {
			state++;
			timer.restart();
			rect.setFillColor(sf::Color::Blue);
		}
		break;
	case 2:
		if (seconds > 3) {
			state = 0;
			timer.restart();
			rect.setFillColor(sf::Color::Cyan);
		}
		break;
	}
	move(delta);
	playerCollide(gameObjects);
}

void Turtle::move(float delta) {
	if (speed < 0) { //moving left
		if (rect.getPosition().x + tileSize.x <= 0) {
			rect.move(sf::Vector2f(windowSize.x + tileSize.x, 0));
		}
	}
	else if (speed > 0) { //moving right
		if (rect.getPosition().x >= windowSize.x) {
			rect.move(sf::Vector2f(-windowSize.x - tileSize.x, 0));
		}
	}
	rect.move(sf::Vector2f(speed * delta, 0));
}

void Turtle::playerCollide(std::vector<std::unique_ptr<GameObject>>& gameObjects) {
	for (std::unique_ptr<GameObject>& object : gameObjects) {
		if (object.get()->typeName == "Player") {
			Player* player = (Player*)object.get();
			if (rect.getGlobalBounds().intersects(player->rect.getGlobalBounds())) {
				if (state == 2) {
					player->rect.setPosition(sf::Vector2f(tileSize.x * (windowSize.x / (tileSize.x * 2)),
						windowSize.y - tileSize.x));
				}
				else {
					player->rect.setPosition(rect.getPosition());
				}
			}
		}
	}
}


void Log::update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta) {
	move(delta);
	playerCollide(gameObjects);
}

void Log::move(float delta) {
	if (speed < 0) { //moving left
		if (rect.getPosition().x + tileSize.x <= 0) {
			rect.move(sf::Vector2f(windowSize.x + tileSize.x, 0));
		}
	}
	else if (speed > 0) { //moving right
		if (rect.getPosition().x >= windowSize.x) {
			rect.move(sf::Vector2f(-windowSize.x - tileSize.x, 0));
		}
	}
	rect.move(sf::Vector2f(speed * delta, 0));
}

void Log::playerCollide(std::vector<std::unique_ptr<GameObject>>& gameObjects) {
	for (std::unique_ptr<GameObject>& object : gameObjects) {
		if (object.get()->typeName == "Player") {
			Player* player = (Player*)object.get();
			if (rect.getGlobalBounds().intersects(player->rect.getGlobalBounds())) {
				player->rect.setPosition(rect.getPosition());
			}
		}
	}
}