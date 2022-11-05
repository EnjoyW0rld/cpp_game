#pragma once
#include "Scene.hpp"
#include "Enemy.hpp"

class FightScene : public Scene {
private:
	bool isPlayerTurn = true;
	Enemy* enemy;
	Character* c;
public:
	FightScene(std::string identifier);
	~FightScene();

	void AssignEnemy(Enemy& enemy);
	void AssignCharacter(Character& character);

	void Update() override;
	void Render(sf::RenderWindow& window) override;
};