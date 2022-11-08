#pragma once
#include "Scene.hpp"
#include "Enemy.hpp"
#include "Highscore.hpp"
#include "SceneManager.hpp"
#include <stdexcept>


class FightScene : public Scene {
private:
	bool isPlayerTurn = true;
	Enemy* enemy;
	Character* c;
	sf::Clock clock;
	const sf::Time& deltaTime;
	Highscore& highScore;
	float pauseTime = 2;

	int currentScore = 0;
public:
	FightScene(const std::string identifier, const sf::Time& deltaTime,Highscore& highScore);
	~FightScene();

	void AssignEnemy(Enemy& enemy);
	void AssignCharacter(Character& character);

	void HandleEvent(const sf::Event& ev, const sf::RenderWindow& window) override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;
	void ChangeTurn(const bool isPlayerTurn);
};