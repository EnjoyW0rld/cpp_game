#include "Enemy.hpp"

Enemy::Enemy(sf::Texture& tex, std::string identifier, TextObject& text) :
	Creature(tex, identifier,text) {
	Randomize(5);
}
Enemy::~Enemy() {}

void Enemy::DoTurn(Creature& character)
{
	int turnType = rand() % 3;
	switch (turnType)
	{
	case 0:
		//int turnDamage = rand() % (GetDamage() + 1);
		Attack(character);
		break;
	case 1:
		Heal();
		break;
	case 2:
		ChangeText(GetName() + " did nothing this turn");
		break;
	}
}


void Enemy::HandleEvent(const sf::Event& ev, const sf::RenderWindow& window)
{
}
