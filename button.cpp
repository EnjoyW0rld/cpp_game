#include "button.hpp"

#include <SFML/Window/Event.hpp>

Button::Button(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color) :
	GameObject(identifier), font(font)
{
	this->shape.setSize(size);
	this->shape.setFillColor(color);
	this->shape.setOutlineColor(sf::Color::White);
	this->shape.setOutlineThickness(1);

	this->text.setFont(font);
	this->text.setString(buttonText);
	this->text.setCharacterSize(26);
	this->text.setFillColor(sf::Color::White);

	sf::FloatRect textRect = this->text.getLocalBounds();
	this->text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

	this->SetPosition(sf::Vector2f(0.0f, 0.0f));
}

Button::~Button() { }

void Button::HandleEvent(const sf::Event& ev, const sf::RenderWindow& window)
{
	if (ev.type == sf::Event::MouseButtonPressed) {
		if (ev.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f size = shape.getSize();
			sf::Vector2f pos = shape.getPosition();
			if (mousePos.x >= pos.x && mousePos.x <= pos.x + size.x &&
				mousePos.y >= pos.y && mousePos.y <= pos.y + size.y) {
				onClick();

			}
		}
	}
}

void Button::onClick()
{
	if (action == nullptr) {
		std::cout << "no function assigned" << std::endl;
		return;
	}
	action();
}

void Button::Update() { }

void Button::Render(sf::RenderWindow& window) {
	window.draw(this->shape);
	window.draw(this->text);
}

void Button::setFontColour(const sf::Color c)
{
	this->text.setFillColor(c);
}

void Button::setCharacterSize(const int size) {
	this->text.setCharacterSize(size);
}

void Button::SetPosition(const sf::Vector2f position) {
	this->shape.setPosition(position);
	sf::Vector2f size = this->shape.getSize();
	sf::Vector2f centerButton(position.x + (size.x / 2.0f), position.y + (size.y / 2.0f));
	this->text.setPosition(centerButton);
}

void Button::SetPosition(const int x, const int y)
{
	SetPosition(sf::Vector2f(x, y));
}

void Button::setButtonAction(std::function<void()> action) {
	this->action = action;
}
void Button::SetBackgroundColour(const sf::Color c)
{
	shape.setFillColor(c);
}