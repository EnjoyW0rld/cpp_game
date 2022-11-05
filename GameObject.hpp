#pragma once
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "Transform.hpp"
#include <vector>

class GameObject {
private:
	std::string identifier;
	std::vector<GameObject*> children;
	GameObject* parent = nullptr;

public:
	sf::Transformable transform;

	GameObject(int x, int y, std::string identifier);
	GameObject(std::string identifier);
	
	virtual ~GameObject(void) {};
	virtual void Update() = 0;
	virtual void Render(sf::RenderWindow& renderWindow);
	void AddChild(GameObject& obj);
	virtual void HandleEvent(const sf::Event& ev,const sf::RenderWindow& window) = 0;
	virtual void SetPosition(sf::Vector2f position);
	std::string GetIdentifier() const;
};