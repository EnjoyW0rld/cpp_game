#include "Creature.hpp"

Creature::Creature(sf::Texture& tex, std::string identifier, TextObject& text) :
	SpriteObject(tex, identifier), text(text)
{

}
Creature::~Creature(void)
{
}


void Creature::Render(sf::RenderWindow& window)
{
	SpriteObject::Render(window);
}
void Creature::HandleEvent(const sf::Event& ev, const sf::RenderWindow& window)
{
}
int Creature::GetHealth() const
{
	return health;
}
int Creature::GetMaxHealth() const
{
	return maxHealth;
}
int Creature::GetDamage() const
{
	return damage;
}

void Creature::Heal() {
	int healAmount = rand() % (intelligence + 1);
	health += healAmount;
	health = health > maxHealth ? maxHealth : health;
	std::string textToShow = GetName() + " healed " + std::to_string(healAmount) + " HP!";
	text.SetText(textToShow);
}
void Creature::ApplyDamage(int damage)
{
	damage = damage - defence;
	damage = damage < 0 ? 0 : damage;
	health -= damage;
	std::string textToShow = GetName() + " got " + std::to_string(damage) + " damage!";
	text.SetText(textToShow);
}
void Creature::Attack(Creature& creature)
{
	int turnDamage = rand() % (damage + 1);
	creature.ApplyDamage(turnDamage);
}
void Creature::Attack(Creature& creature, int& damage)
{
	int turnDamage = rand() % (damage + 1);
	damage = turnDamage;
	creature.ApplyDamage(turnDamage);
}
void Creature::SetName(const std::string name)
{
	this->name = name;
}
void Creature::ChangeText(const std::string textToShow)
{
	text.SetText(textToShow);
}

std::string Creature::GetName() const{
	return name;
}
int Creature::GetAttribute(attribute at) const
{
	switch (at)
	{
	case Creature::_intelligence:
		return intelligence;
	case Creature::_strength:
		return strength;
	case Creature::_agility:
		return agility;
	}
}
void Creature::Randomize(const int points)
{
	intelligence = 1, strength = 1, agility = 1;
	for (int i = 0; i < points; i++)
	{
		int attribute = 1 + (rand() % 100);
		if (attribute <= 33) {
			intelligence++;
			continue;
		}
		if (attribute > 33 && attribute <= 66) {
			strength++;
			continue;
		}
		if (attribute > 66) {
			agility++;
			continue;
		}
	}
	maxHealth = strength * 1.5;
	health = maxHealth;
	damage = agility * 1.5;
	defence = strength * .2;
}