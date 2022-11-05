#include "GameObject.hpp"

GameObject::GameObject(int x, int y, std::string identifier)
{
	transform.setPosition(x, y);
	this->identifier = identifier;
}

GameObject::GameObject(std::string identifier)
{
	transform.setPosition(0, 0);
	this->identifier = identifier;
}

void GameObject::Render(sf::RenderWindow& renderWindow)
{
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->Render(renderWindow);
	}
}

void GameObject::AddChild(GameObject& obj)
{
	if (obj.parent != nullptr) return;
	obj.parent = this;
	this->children.push_back(&obj);
}

std::string GameObject::GetIdentifier() const
{
	return this->identifier;
}

void GameObject::SetPosition(sf::Vector2f position)
{
	this->transform.setPosition(position);
}
