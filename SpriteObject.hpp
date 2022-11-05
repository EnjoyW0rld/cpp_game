#pragma once
#include "GameObject.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class SpriteObject : public GameObject {
private:
	sf::Sprite spr;
	sf::Texture tex;

public:
	SpriteObject(std::string spriteFile,std::string identifier);
	SpriteObject(sf::Texture& tex,std::string identifier);
	SpriteObject(std::string spriteFile,std::string identifier,int x,int y);
	~SpriteObject(void);

	
	void SetScale(sf::Vector2f scale);
	void SetScale(int scale);
	void SetPosition(sf::Vector2f position) override;
	virtual void Update() override;
	virtual void Render(sf::RenderWindow& renderWindow) override;
	virtual void HandleEvent(const sf::Event& ev,const sf::RenderWindow& window) override;
};