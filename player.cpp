#include"player.h"

Player::Player(int x, int y) {
	Player::GameObject::GameObject(x, y, 120, 120, sf::Color::Blue);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(rect);
};

void Player::update(Game& gameState, float delta) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		rect.move(sf::Vector2f(120, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		rect.move(sf::Vector2f(-120, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		rect.move(sf::Vector2f(0, -120));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		rect.move(sf::Vector2f(0, 120));
	}
};