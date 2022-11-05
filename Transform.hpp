#pragma once
#include "SFML/System/Vector2.hpp"

class Transform {
public:
	sf::Vector2f pos;

	Transform(int x, int y) { SetPosition(x, y); };
	~Transform(void) {};

	void SetPosition(int x,int y) {
		this->pos.x = x;
		this->pos.y = y;
	}
};