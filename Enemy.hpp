#pragma once
#include "SpriteObject.hpp"
#include "Character.hpp"
//class Character;

class Enemy : public SpriteObject {
private:
	int health, maxHealth, damage, defence;
	int intelligence, strength, agility;
public:
	Enemy(sf::Texture& tex,std::string identifier);
	~Enemy(void);


	void RandomizeEnemy(int maxPoints);
	// Inherited via GameObject
	void Update() override;
	void HandleEvent(const sf::Event& ev, const sf::RenderWindow& window) override;
	void AttackCharacter(Character& character);
	void DoTurn(Character& character);
	void Heal();
};