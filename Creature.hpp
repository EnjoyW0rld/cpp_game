#pragma once
#include "SpriteObject.hpp"
#include "TextObject.hpp"

class Creature : public SpriteObject{
private:
	TextObject& text;
	int health, maxHealth, damage, defence;
	int intelligence, strength, agility;
	std::string name;
public:
	enum attribute { _intelligence, _strength, _agility };
	Creature(sf::Texture& tex, std::string identifier,TextObject& text);
	~Creature(void);

	void Render(sf::RenderWindow& window) override;
	void HandleEvent(const sf::Event& ev, const sf::RenderWindow& window) override;
	void Heal();

	void ApplyDamage(int damage);
	void Attack(Creature& creature);
	void Attack(Creature& creature, int& damage);

	int GetDamage() const;
	int GetHealth() const;
	int GetMaxHealth() const;
	std::string GetName() const;
	int GetAttribute(attribute at) const;

	void ChangeText(const std::string textToShow);
	void SetName(const std::string name);
	void Randomize(const int points);
};