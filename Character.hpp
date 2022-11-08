#pragma once
#include "SpriteObject.hpp"
#include "Enemy.hpp"
#include "Creature.hpp"

class Enemy;

class Character : public Creature {
//private:
	//int health, maxHealth, damage, defence;
	//int intelligence, strength, agility;

public:
	Character(sf::Texture& tex, std::string identifier, TextObject& text);
	~Character(void);

	void HandleEvent(const sf::Event& ev, const sf::RenderWindow& window) override;
};