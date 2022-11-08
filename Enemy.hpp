#pragma once
#include "SpriteObject.hpp"
#include "Character.hpp"
#include "Creature.hpp"
#include "TextObject.hpp"

class Enemy : public Creature {
public:
	Enemy(sf::Texture& tex,std::string identifier, TextObject& text);
	~Enemy(void);


	// Inherited via GameObject
	//void SetText(std::string textToShow);
	void SetOnDieText();
	void HandleEvent(const sf::Event& ev, const sf::RenderWindow& window) override;
	void DoTurn(Creature& character);
};