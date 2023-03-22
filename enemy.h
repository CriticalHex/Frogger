#pragma once
#include"player.h"

class Enemy : public GameObject {
public:
	Enemy(sf::Vector2f position, sf::Color color, std::string type) :
		GameObject(position.x, position.y, tileSize, color, type) {};
	virtual void update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta);
	virtual void playerCollide(std::vector<std::unique_ptr<GameObject>>& gameObjects);
	int speed;
	sf::Vector2f spawnPoint;
private:
};

class Car : public Enemy {
	Car(sf::Vector2f position, int speed) : Enemy(position, sf::Color::Red, "Car")
		{ this->speed = speed; spawnPoint = position; };
	void update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta);
	void playerCollide(std::vector<std::unique_ptr<GameObject>>& gameObjects);
};