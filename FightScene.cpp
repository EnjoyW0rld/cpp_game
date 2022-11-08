#include "FightScene.hpp"


FightScene::FightScene(const std::string identifier, const sf::Time& deltaTime, Highscore& highScore) :
	Scene(identifier), deltaTime(deltaTime), highScore(highScore)
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

		if (pauseTime <= 0) {
			if (enemy == nullptr) {
				throw std::logic_error("sss");
			}
			enemy->DoTurn(*c);
			std::cout << "enemy did turn" << std::endl;
			ChangeTurn(true);
			pauseTime = 2;
		}
		if (pauseTime > 0) {
			pauseTime -= deltaTime.asSeconds();
			std::cout << pauseTime << std::endl;
		}
	}
	Scene::Update();
}
void FightScene::Render(sf::RenderWindow& window)
{
	enemy->Render(window);
	c->Render(window);
	Scene::Render(window);
}
void FightScene::ChangeTurn(const bool isPlayerTurn)
{
	if (c->GetHealth() <= 0) {
		highScore.AddScore({ "myName",currentScore });
		currentScore = 0;
		GetSceneManager().SetScene("menu");
		c->Randomize(5);
		enemy->Randomize(5);
	}
	if (enemy->GetHealth() <= 0) {
		currentScore++;
		enemy->SetOnDieText();
		enemy->Randomize(5 + (currentScore * .5));
	}
	this->isPlayerTurn = isPlayerTurn;
}