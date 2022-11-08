#include "GameObject.hpp"

GameObject::GameObject(const int x,const int y,const std::string identifier) :
	identifier(identifier)
{
	transform.setPosition(x, y);
}

GameObject::GameObject(const std::string identifier) :
	identifier(identifier)
{
	transform.setPosition(0, 0);
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

void GameObject::SetPosition(const sf::Vector2f position)
{
	this->transform.setPosition(position);
}
