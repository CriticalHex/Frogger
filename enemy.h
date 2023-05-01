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
	{
		this->speed = speed;
	};
	void update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta);
	void playerCollide(std::vector<std::unique_ptr<GameObject>>& gameObjects);
	void move(float delta);
private:
};

class Turtle : public Enemy {
public:
	Turtle(sf::Vector2f position, float speed, int seconds) : Enemy(position, sf::Color::Cyan, "Turtle")
	{
		this->speed = speed;
		timeOffset = seconds;
	};
	void update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta);
	void playerCollide(std::vector<std::unique_ptr<GameObject>>& gameObjects);
	void move(float delta);
	sf::Clock timer;
	sf::Time timeElapsed;
	int state = 0;
	int timeOffset;
private:
};


class Log : public Enemy {
public:
	Log(sf::Vector2f position, float speed) : Enemy(position, sf::Color::Color(150,75,0), "Log")
	{
		this->speed = speed;
	};
	void update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta);
	void playerCollide(std::vector<std::unique_ptr<GameObject>>& gameObjects);
	void move(float delta);
private:
};