#include "SpriteObject.hpp"


SpriteObject::SpriteObject(const std::string spriteFile,const std::string identifier) :  GameObject(0,0,identifier)
{
	this ->tex.loadFromFile(spriteFile);
	this ->spr.setTexture(tex);
}

SpriteObject::SpriteObject(const std::string spriteFile,const std::string identifier, const int x, const int y) : 
	GameObject(x,y,identifier)
{
	this->tex.loadFromFile(spriteFile);
	this->spr.setTexture(tex);
	spr.setPosition(transform.getPosition());
}
SpriteObject::SpriteObject(const sf::Texture& tex, const std::string identifier)
	: GameObject(identifier)
{
	this->spr.setTexture(tex);
}

SpriteObject::~SpriteObject(void)
{
}

void SpriteObject::Update()
{
	//spr.setPosition(transform.getPosition());
}
/// <summary>
/// Set scale of the sprite (1,1) are default values
/// </summary>
/// <param name="scale"></param>
void SpriteObject::SetScale(const sf::Vector2f scale)
{
	spr.setScale(scale);
}
void SpriteObject::SetScale(const int scale)
{
	spr.setScale(sf::Vector2f(scale,scale));
}

void SpriteObject::SetPosition(sf::Vector2f position)
{
	spr.setPosition(position);
}

void SpriteObject::Render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(spr);
	GameObject::Render(renderWindow);
}

void SpriteObject::HandleEvent(const sf::Event& ev,const sf::RenderWindow& window)
{
}
