#pragma once
#include <SFML/Graphics.hpp>


class GravitySource
{
public:
	GravitySource(float pos_x, float pos_y, float strength);
	void render(sf::RenderWindow& window);
	sf::Vector2f getPos() { return pos; }
	float getStrength() { return strength; }
private:
	sf::Vector2f pos;
	float strength;
	sf::CircleShape s;
};

