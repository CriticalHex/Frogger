#include"player.h"

void Player::draw(sf::RenderWindow& window) {
	window.draw(rect);
};

void Player::update(Game& gameState, float delta) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		rect.move(sf::Vector2f(tileSize.x, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		rect.move(sf::Vector2f(-tileSize.x, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		rect.move(sf::Vector2f(0, -tileSize.y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		rect.move(sf::Vector2f(0, tileSize.y));
	}
};