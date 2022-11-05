#pragma once
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "GameObject.hpp"

class Scene {
private:
	std::vector<GameObject*> gameObjects;
	std::string name;
public:
	Scene(std::string identifier);
	~Scene(void);

	void AddGameObject(GameObject& gameObject);
	virtual void HandleEvent(const sf::Event& ev,const sf::RenderWindow& window);
	virtual void Update();
	virtual void Render(sf::RenderWindow& window);
	GameObject& GetObject(const std::string objName);
	std::string GetName() const;
};