#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "Scene.hpp"
#include <SFML/Window/Event.hpp>



class SceneManager {
private:
	Scene* currentScene;
public:
	std::vector<Scene*> scenes;
	SceneManager(Scene& firstScene);
	~SceneManager(void);

	void AddScene(Scene& scene);
	Scene* GetScene(std::string identifier) const;
	void HandleEvent(const sf::Event& ev, const sf::RenderWindow& window);
	void SetScene(std::string identifier);
	void Update();
	void Render(sf::RenderWindow& window);
};