//25 book
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
//#include"Scene.hpp"
#include "SpriteObject.hpp"
#include "button.hpp"
#include "SceneManager.hpp"
#include "Highscore.hpp"
#include "TextObject.hpp"
#include "Character.hpp"
#include "FightScene.hpp"
#include "Enemy.hpp"

int main() {
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(1280, 720), "TEst");
	sf::Event e;
	sf::Clock clock;
	sf::Time elapsed;
	sf::Color textColour = sf::Color::Red;

	Scene menu("menu");
	FightScene game("game");
	SceneManager sceneManager(menu);

	sf::Font f;
	f.loadFromFile("Lato-Regular.ttf");
	sf::Texture texture;
	texture.loadFromFile("frog.png");
	sf::Texture textureEnemy;
	textureEnemy.loadFromFile("denji.jpg");

#pragma region GameScene


	Character character(texture, "character");
	character.SetPosition({ 200,200 });
	Enemy enemy(textureEnemy, "enemy");
	enemy.SetScale({.3,.3});
	enemy.SetPosition({ 500,200 });
	game.AssignCharacter(character);
	game.AssignEnemy(enemy);

	Button back("back", f, "back", { 100,100 }, textColour);
	back.setButtonAction([&sceneManager] {
		sceneManager.SetScene("menu");
		});
	game.AddGameObject(back);

	Button attackButton("attack", f, "Attack Enemy", { 200,100 }, textColour);
	attackButton.SetPosition( 500,300 );
	attackButton.setButtonAction([&enemy,&character] {
		character.AttackEnemy(enemy);
		});
	game.AddGameObject(attackButton);


#pragma region TextObjects


	TextObject characterHealth("characterHealth", f, "health");
	characterHealth.SetActionPerUpdate([&character,&characterHealth] {
		std::string textToShow =
			"Health - " + std::to_string(character.GetHealth()) + "/" + std::to_string(character.GetMaxHealth());
		characterHealth.SetText(textToShow);
		});
	characterHealth.SetColour(sf::Color::Blue);
	characterHealth.SetPosition({ 200,300 });
	game.AddGameObject(characterHealth);

	TextObject enemyHealth("enemyHealth", f, "health");
	enemyHealth.SetActionPerUpdate([&enemy , &enemyHealth] {
		std::string textToShow =
			"Health - " + std::to_string(enemy.GetHealth()) + "/" + std::to_string(enemy.GetMaxHealth());
		//std::cout << textToShow << std::endl;
		enemyHealth.SetText(textToShow);
		});
	enemyHealth.SetColour(sf::Color::Blue);
	enemyHealth.SetPosition({ 500,10 });
	game.AddGameObject(enemyHealth);
#pragma endregion

#pragma endregion

#pragma region  Menu


	Highscore highScore("test.txt", "HighScore", f);
	highScore.transform.setPosition({ 100,200 });
	highScore.SetSpaceBetween(50);
	menu.AddGameObject(highScore);

	TextObject rateHeader("rateHeader", f, "High scores");
	rateHeader.SetColour(textColour);
	rateHeader.SetPosition({ 100,120 });
	menu.AddGameObject(rateHeader);

	//quit button
	Button quit("Quit", f, "Quit", sf::Vector2f(200, 100), sf::Color::White);
	quit.SetPosition(1000, 500);
	quit.setFontColour(textColour);
	quit.setButtonAction([&window]() {
		window.close();
		});
	menu.AddGameObject(quit);

	//erase button
	Button eraseData("Erase", f, "Erase data", sf::Vector2f(200, 100), sf::Color::White);
	eraseData.SetPosition(1000, 300);
	eraseData.setFontColour(textColour);
	menu.AddGameObject(eraseData);

	//Swithc scene to play button
	Button play("SwitchScene", f, "switch next", sf::Vector2f(200, 100), sf::Color::White);
	play.SetPosition(sf::Vector2f(1000, 100));
	play.setFontColour(textColour);
	play.setButtonAction([&sceneManager]()
		{
			sceneManager.SetScene("game");
		}
	);

	menu.AddGameObject(play);
#pragma endregion

	sceneManager.AddScene(game);


	elapsed = clock.getElapsedTime();


	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
			else {
				sceneManager.HandleEvent(e, window);
			}
		}
		window.clear();
		sceneManager.Update();
		sceneManager.Render(window);
		window.display();
		elapsed = clock.getElapsedTime();
		clock.restart();

	}

	return 0;
}