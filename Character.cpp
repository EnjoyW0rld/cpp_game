#include "Character.hpp"

Character::Character(sf::Texture& tex, std::string identifier) :
	SpriteObject(tex, identifier) {
	RandomizeCharacter();
}
Character::~Character() {}

void Character::GetDamage(int damage)
{
	damage = damage > defence ? damage - defence : 0;
	health -= damage;
}

int Character::GetHealth() const
{
	return health;
}
int Character::GetMaxHealth() const
{
	return maxHealth;
}

void Character::RandomizeCharacter()
{
	intelligence = 1, strength = 1, agility = 1;
	for (int i = 0; i < 5; i++)
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
	damage = agility;
	defence = strength;
}
void Character::Heal()
{
	int healAmount = rand() % intelligence;
	health += healAmount;
	health = health > maxHealth ? maxHealth : health;
}

void Character::Update()
{
}
void Character::Render(sf::RenderWindow& window) {
	SpriteObject::Render(window);
}
void Character::HandleEvent(const sf::Event& ev, const sf::RenderWindow& window)
{
}