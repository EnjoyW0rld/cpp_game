#pragma once
#include "SpriteObject.hpp"

class Character : public SpriteObject {
private:
	int health, maxHealth, damage, defence;
	int intelligence, strength, agility;

public:
	Character(sf::Texture& tex, std::string identifier);
	~Character(void);

	// Inherited via GameObject
	void Update() override;
	void Render(sf::RenderWindow& window) override;
	void HandleEvent(const sf::Event& ev, const sf::RenderWindow& window) override;
	void GetDamage(int damage);

	int GetHealth() const;
	int GetMaxHealth() const;
	void RandomizeCharacter();
	void Heal();
};