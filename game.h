#pragma once
#include<vector>
#include"globals.h"

class GameObject;

class Game
{
public:
	Game();
	void run();
private:
	void initialize();
	void garbageCollect();
	std::vector<std::unique_ptr<GameObject>> gameObjects; // std::make_unique<GameObject>();
	sf::RenderWindow window;
	sf::Event gameEvent;
	sf::Color bgColor = sf::Color(6, 8, 12);
	sf::Clock clock;
	sf::Time delta;
};


class GameObject {
public:
	sf::RectangleShape rect;
	bool remove = false;
	std::string typeName;
	GameObject() {};
	GameObject(int x, int y, sf::Vector2f size, sf::Color color, std::string type);
	void draw(sf::RenderWindow& window);
	virtual void update(std::vector<std::unique_ptr<GameObject>>& gameObjects, float delta) = 0;
};