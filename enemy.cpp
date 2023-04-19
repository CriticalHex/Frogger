#include"enemy.h"
#include<typeinfo>
#include<iostream>
using namespace std;

void Car::update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta) {
	if (speed < 0) { //moving left
		if (rect.getPosition().x + tileSize.x <= 0) {
			rect.move(sf::Vector2f(windowSize.x, 0));
		}
	}
	else if (speed > 0) { //moving right
		if (rect.getPosition().x >= windowSize.x) {
			rect.move(sf::Vector2f(-windowSize.x, 0));
		}
	}
	rect.move(sf::Vector2f(speed * delta, 0));
	//cout << speed << endl;
}

void Car::playerCollide(std::vector<std::unique_ptr<GameObject>>& gameObjects) {
	for (std::unique_ptr<GameObject>& object : gameObjects) {
		if (object.get()->typeName == "Player") {
			Player* player = (Player*)object.get();
			if (rect.getGlobalBounds().intersects(player->rect.getGlobalBounds())) {
				//gameover
				object.release();
			}
		}
	}
}
