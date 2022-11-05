#include "Enemy.hpp"

Enemy::Enemy(sf::Texture& tex, std::string identifier) : SpriteObject(tex, identifier) {
	RandomizeEnemy(10);
}
Enemy::~Enemy() {}

void Enemy::RandomizeEnemy(int maxPoints)
{
	intelligence = 1, strength = 1, agility = 1;
	for (int i = 0; i < maxPoints; i++)
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
	defence = strength * .5;
	std::cout << health << std::endl;
	std::cout << damage << std::endl;
	std::cout << defence << std::endl;

}
void Enemy::AttackCharacter(Character& character)
{
	character.GetDamage(damage);
}
void Enemy::Heal()
{
	int healAmount = rand() % intelligence;
	health += healAmount;
	health = health > maxHealth ? maxHealth : health;
}
void Enemy::DoTurn(Character& character)
{
	int turnType = rand() % 3;
	switch (turnType)
	{
	case 0:
		AttackCharacter(character);
		break;
	case 1:
		Heal();
		break;
	case 2:
		break;
	}
}

void Enemy::GetDamage(int damage)
{
	damage = damage - defence;
	damage = damage < 0 ? 0 : damage;
	health -= damage;
	std::cout << defence << std::endl;
}
int Enemy::GetAttribute(attribute at) const
{
	switch (at)
	{
	case _intelligence:
		return intelligence;
	case _agility:
		return agility;
	case _strength:
		return strength;
	}
}


int Enemy::GetMaxHealth() const
{
	return maxHealth;
}
int Enemy::GetHealth() const
{
	return health;
}

void Enemy::Update()
{
}
void Enemy::HandleEvent(const sf::Event& ev, const sf::RenderWindow& window)
{
}
