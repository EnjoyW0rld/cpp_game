#include "Character.hpp"

Character::Character(sf::Texture& tex, std::string identifier, TextObject& text) :
	Creature(tex, identifier,text) {
	Randomize(5);
}
Character::~Character() {}

void Character::HandleEvent(const sf::Event& ev, const sf::RenderWindow& window)
{
}