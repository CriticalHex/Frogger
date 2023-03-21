#pragma once
#include"game.h"

class Player : public GameObject {
public:
	Player(int x = 8 * 120, int y = 120);
	void draw(sf::RenderWindow& window);
	void update(Game& gameState, float delta);
private:

};