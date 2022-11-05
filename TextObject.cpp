#include "TextObject.hpp"

TextObject::TextObject(std::string identifier, sf::Font& font, std::string text) :
	GameObject(identifier), font(font)
{
	SetText(text);
	this->text.setFont(font);
}

TextObject::~TextObject(void)
{
}

void TextObject::SetColour(sf::Color c)
{
	this->text.setFillColor(c);
}
void TextObject::SetFontSize(int size)
{
	this->text.setCharacterSize(size);
}
void TextObject::SetText(const std::string newText)
{
	this->text.setString(newText);
}

void TextObject::SetPosition(sf::Vector2f pos)
{
	this->text.setPosition(pos);
}
void TextObject::Update()
{
	if (action != nullptr) {
		this->action();
	}
}
void TextObject::Render(sf::RenderWindow& window)
{
	GameObject::Render(window);
	window.draw(text);
}
void TextObject::SetActionPerUpdate(std::function<void()> action)
{
	this->action = action;
}
void TextObject::HandleEvent(const sf::Event& ev, const sf::RenderWindow& window)
{
}