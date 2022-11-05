#include "Scene.hpp"

Scene::Scene(std::string identifier) {
	this->name = identifier;
}

Scene::~Scene() {

}
void Scene::AddGameObject(GameObject& gameObject)
{
	gameObjects.push_back(&gameObject);
}
void Scene::HandleEvent(const sf::Event& ev,const  sf::RenderWindow& window)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->HandleEvent(ev,window);
	}
}
void Scene::Update() {
	for (int i = 0; i < this->gameObjects.size(); i++)
	{
		this->gameObjects[i]->Update();
	}
}
void Scene::Render(sf::RenderWindow& window) {
	for (int i = 0; i < this->gameObjects.size(); i++)
	{
		this->gameObjects[i]->Render(window);
	}
}

GameObject& Scene::GetObject(const std::string objName)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->GetIdentifier() == objName) {
			return *(gameObjects[i]);
		}
	}
}

std::string Scene::GetName() const
{
	return name;
}
