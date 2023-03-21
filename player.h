#pragma once
#include"game.h"

class Player : public GameObject {
public:
	Player() : 
		GameObject(tileSize.x* (windowSize.x / (tileSize.x * 2)), windowSize.y - tileSize.y, tileSize, sf::Color::Blue) {};
	void draw(sf::RenderWindow& window);
	void update(Game& gameState, float delta);
private:
};