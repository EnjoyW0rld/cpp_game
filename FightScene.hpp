#pragma once
#include "Scene.hpp"
#include "Enemy.hpp"
#include "Highscore.hpp"

class FightScene : public Scene {
private:
	bool isPlayerTurn = true;
	Enemy* enemy;
	Character* c;
	sf::Clock clock;
	sf::Time& deltaTime;
	Highscore& highScore;
	float pauseTime = 2;

	int currentScore;
public:
	FightScene(std::string identifier, sf::Time& deltaTime,Highscore& highScore);
	~FightScene();

	void AssignEnemy(Enemy& enemy);
	void AssignCharacter(Character& character);

	void HandleEvent(const sf::Event& ev, const sf::RenderWindow& window) override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;
	void ChangeTurn(bool isPlayerTurn);
};