#include "SceneManager.hpp"

SceneManager::SceneManager(Scene& firstScene) : currentScene(&firstScene) {
	scenes.push_back(&firstScene);
}
SceneManager::~SceneManager(void) {  };

void SceneManager::AddScene(Scene& scene) {
	scenes.push_back(&scene);
	scene.SetParent(*(this));
}

Scene* SceneManager::GetScene(std::string identifier) const
{
	for (int i = 0; i < scenes.size(); i++)
	{
		if (scenes[i]->GetName() == identifier) return scenes[i];
	}

}

void SceneManager::HandleEvent(const sf::Event& ev, const sf::RenderWindow& window)
{
	(*currentScene).HandleEvent(ev, window);
}

void SceneManager::SetScene(std::string identifier)
{
	currentScene = this->GetScene(identifier);
}
void SceneManager::Update()
{
	(*currentScene).Update();
}

void SceneManager::Render(sf::RenderWindow& window)
{
	(*currentScene).Render(window);
}
