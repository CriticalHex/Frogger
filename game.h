#pragma once
#include<vector>
#include<SFML/Graphics.hpp>

class GameObject;

class Game
{
public:
	Game();
	void run();
private:
	std::vector<std::unique_ptr<GameObject>> gameObjects;// std::make_unique;
	sf::RenderWindow window;
	sf::Event gameEvent;
	sf::Color bgColor = sf::Color(6, 8, 12);
};


class GameObject {
public:
	//vars
	sf::RectangleShape rect;
	bool remove = false;
	//functions
	GameObject() {};
	GameObject(int x, int y, int width, int height, sf::Color color = sf::Color::White);
	virtual void draw(sf::RenderWindow& window) {};
	virtual void update(Game& gameState, float delta) {};
};