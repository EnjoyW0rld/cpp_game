#pragma once
#include "GameObject.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class SpriteObject : public GameObject {
private:
	sf::Sprite spr;
	sf::Texture tex;

public:
	SpriteObject(const std::string spriteFile,const std::string identifier);
	SpriteObject(const sf::Texture& tex,const std::string identifier);
	SpriteObject(const std::string spriteFile,const std::string identifier,const int x,const int y);
	~SpriteObject(void);

	
	void SetScale(const sf::Vector2f scale);
	void SetScale(const int scale);
	void SetPosition(sf::Vector2f position) override;
	virtual void Update() override;
	virtual void Render(sf::RenderWindow& renderWindow) override;
	virtual void HandleEvent(const sf::Event& ev,const sf::RenderWindow& window) override;
};