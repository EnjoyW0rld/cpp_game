#pragma once
#include "GameObject.hpp"
#include "SFML/Graphics/Text.hpp"
#include <string>
#include <functional>

class TextObject : public GameObject {
	sf::Text text;
	sf::Font& font;

	std::function<void()> action;
public:
	TextObject(std::string identifier,sf::Font& font,std::string text);
	~TextObject(void);
	
	void SetColour(sf::Color c);
	void SetFontSize(int size);
	void SetText(const std::string newText);

	// Inherited via GameObject
	void Update() override;
	void SetPosition(sf::Vector2f pos) override;
	void Render(sf::RenderWindow& window) override;
	void HandleEvent(const sf::Event& ev, const sf::RenderWindow& window) override;
	void SetActionPerUpdate(std::function<void()> action);
};