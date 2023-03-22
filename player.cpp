#include"player.h"

void Player::move(sf::Vector2f direction) {
	rect.move(direction);
	timer.restart();
}

void Player::update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta) {
	timeElapsed = timer.getElapsedTime();
	if (timeElapsed.asMilliseconds() >= 10 * msFrameTime) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			move(sf::Vector2f(tileSize.x, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			move(sf::Vector2f(-tileSize.x, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			move(sf::Vector2f(0, -tileSize.y));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			move(sf::Vector2f(0, tileSize.y));
		}
	}
};