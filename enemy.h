#pragma once
#include"player.h"

class Enemy : public GameObject {
public:
	Enemy(sf::Vector2f position, sf::Color color, std::string type) :
		GameObject(position.x, position.y, tileSize, color, type) {};
	virtual void update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta) = 0;
	virtual void playerCollide(std::vector<std::unique_ptr<GameObject>>& gameObjects) = 0;
	float speed;
private:
};

class Car : public Enemy {
public:
	Car(sf::Vector2f position, float speed) : Enemy(position, sf::Color::Red, "Car")
		{ this->speed = speed; };
	void update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta);
	void playerCollide(std::vector<std::unique_ptr<GameObject>>& gameObjects);
private:
};