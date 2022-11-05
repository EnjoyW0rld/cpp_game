#pragma once
#include "SpriteObject.hpp"
#include "Enemy.hpp"
#include "Creature.hpp"

class Enemy;

class Character : public Creature {
private:
	int health, maxHealth, damage, defence;
	int intelligence, strength, agility;

public:
	Character(sf::Texture& tex, std::string identifier, TextObject& text);
	~Character(void);

	// Inherited via GameObject
	//void Update() override;
	//void Render(sf::RenderWindow& window) override;
	void HandleEvent(const sf::Event& ev, const sf::RenderWindow& window) override;
	//void GetDamage(int damage);

	//void AttackEnemy(Enemy& enemy);

	//int GetHealth() const; //
	//int GetMaxHealth() const; //
	//void RandomizeCharacter(); //
	//void Heal(); //
};