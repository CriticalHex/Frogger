#include"player.h"

void Player::move(sf::Vector2f direction) {
	if (!moved) {
		if (!wallCollision(direction)) {
			rect.move(direction);
		}
		moved = true;
	}
	//timer.restart();
}

void Player::update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta) {
	//timeElapsed = timer.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		move(sf::Vector2f(tileSize.x, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		move(sf::Vector2f(-tileSize.x, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		move(sf::Vector2f(0, -tileSize.y));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		move(sf::Vector2f(0, tileSize.y));
	}
	else {
		moved = false;
	}
};

bool Player::wallCollision(sf::Vector2f direction) {
	sf::Vector2f newpos = rect.getPosition() + direction;
	return (newpos.x < 0 or newpos.x + rect.getSize().x > windowSize.x or newpos.y < 0 or newpos.y + rect.getSize().y > windowSize.y);
}