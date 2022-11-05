#include "FightScene.hpp"

FightScene::FightScene(std::string identifier) : Scene(identifier)
{
	
}
FightScene::~FightScene()
{

}

void FightScene::AssignEnemy(Enemy& enemy)
{
	this->enemy = &enemy;
}
void FightScene::AssignCharacter(Character& character)
{
	c = &character;
}

void FightScene::Update()
{
	Scene::Update();
}
void FightScene::Render(sf::RenderWindow& window)
{
	enemy->Render(window);
	c->Render(window);
	Scene::Render(window);
}