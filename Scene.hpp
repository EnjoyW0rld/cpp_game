#pragma once
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "GameObject.hpp"

class SceneManager;

class Scene {
private:
	std::vector<GameObject*> gameObjects;
	std::string name;

	SceneManager* sceneManager;
public:
	Scene(std::string identifier);
	~Scene(void);

	void AddGameObject(GameObject& gameObject);
	void SetParent(SceneManager& manager);
	virtual void HandleEvent(const sf::Event& ev,const sf::RenderWindow& window);
	virtual void Update();
	virtual void Render(sf::RenderWindow& window);
	GameObject& GetObject(const std::string objName);
	SceneManager& GetSceneManager() const;
	std::string GetName() const;
};