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
void FightScene::HandleEvent(const sf::Event& ev, const sf::RenderWindow& window)
{
	if (isPlayerTurn) {
		Scene::HandleEvent(ev, window);
	}
}
void FightScene::Update()
{
	if (!isPlayerTurn) {
		enemy->DoTurn(*c);
		ChangeTurn(true);
	}
	Scene::Update();
}
void FightScene::Render(sf::RenderWindow& window)
{
	enemy->Render(window);
	c->Render(window);
	Scene::Render(window);
}
void FightScene::ChangeTurn(bool isPlayerTurn)
{
	this->isPlayerTurn = isPlayerTurn;
}