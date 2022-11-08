#include "Enemy.hpp"

Enemy::Enemy(sf::Texture& tex, std::string identifier, TextObject& text) :
	Creature(tex, identifier,text) {
	Randomize(5);
}
Enemy::~Enemy() {}

void Enemy::DoTurn(Creature& character)
{
	
	//int turnType = rand() % 3;
	int turnType = (rand() % 100) + 1;
	if (turnType <= 30) {
		Attack(character);
		return;
	}if (turnType > 30 && turnType <= 60) {
		Heal();
		return;
	}if (turnType > 60) {
		ChangeText(GetName() + " did nothing this turn");
		return;
	}
}
void Enemy::SetOnDieText()
{
	std::string textToShow = GetName() + " died!";
	ChangeText(textToShow);
}

void Enemy::HandleEvent(const sf::Event& ev, const sf::RenderWindow& window)
{
}
