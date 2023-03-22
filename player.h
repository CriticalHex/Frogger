#pragma once
#include"game.h"

class Player : public GameObject {
public:
	Player() : 
		GameObject(
			tileSize.x* (windowSize.x / (tileSize.x * 2)), 
			windowSize.y - tileSize.y, tileSize,
			sf::Color::Green, "Player") {};
	void update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta);
	void move(sf::Vector2f direction);
	sf::Clock timer;
	sf::Time timeElapsed;
private:
};