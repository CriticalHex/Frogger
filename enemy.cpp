#include"enemy.h"
#include<typeinfo>

void Car::update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta) {
	if (speed < 0) { //moving left
		if (rect.getPosition().x + tileSize.x <= 0) {
			rect.setPosition(spawnPoint);
		}
	}
	else if (speed > 0) { //moving right
		if (rect.getPosition().x >= windowSize.x) {
			rect.setPosition(spawnPoint);
		}
	}
	rect.move(sf::Vector2f(speed * delta, 0));
}

void Car::playerCollide(std::vector<std::unique_ptr<GameObject>>& gameObjects) {
	for (std::unique_ptr<GameObject>& object : gameObjects) {
		if (object.get()->typeName == "Player") {

			Player* player = object.get();

		}
	}
}
