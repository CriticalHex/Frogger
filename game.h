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
};


class GameObject {
public:
	//vars
	sf::RectangleShape rect;
	bool remove = false;
	//functions
	GameObject() {};
	~GameObject() {};
	virtual void draw(sf::RenderWindow& window);
	virtual void update(Game& gameState, float delta);
};