//25 book
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
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
	sf::Font f;
	f.loadFromFile("Lato-Regular.ttf");

	Highscore highScore("test.txt", "HighScore", f,200);


	Scene menu("menu");
	FightScene game("game",elapsed,highScore);
	SceneManager sceneManager(menu);

	sf::Texture texture;
	texture.loadFromFile("heart_broken.png");
	sf::Texture textureEnemy;
	textureEnemy.loadFromFile("denji.jpg");

#pragma region GameScene

	TextObject stateText("state", f, " nnnnn");
	game.AddGameObject(stateText);
	stateText.SetPosition({ 200,600 });

	Character character(texture, "character",stateText);
	character.SetName("You");
	character.SetPosition({ 260,250 });
	Enemy enemy(textureEnemy, "enemy",stateText);
	enemy.SetName("enemy");
	enemy.SetScale({.3,.3});
	enemy.SetPosition({ 1010,250 });
	game.AssignCharacter(character);
	game.AssignEnemy(enemy);

	Button back("back", f, "back", { 100,100 }, textColour);
	back.setButtonAction([&sceneManager] {
		sceneManager.SetScene("menu");
		});
	game.AddGameObject(back);


	Button healButton("Heal", f, "Heal", { 150,50 }, textColour);
	healButton.SetPosition(200, 500);
	healButton.setButtonAction([&character, &game]{
		character.Heal();
		game.ChangeTurn(false);
		});
	game.AddGameObject(healButton);

	Button attackButton("attack", f, "Attack Enemy", { 150,50 }, textColour);
	attackButton.SetPosition( 200,430 );
	attackButton.setButtonAction([&enemy,&character,&game] {
		character.Attack(enemy);
		game.ChangeTurn(false);
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
		enemyHealth.SetText(textToShow);
		});
	enemyHealth.SetColour(sf::Color::Blue);
	enemyHealth.SetPosition({ 500,10 });
	game.AddGameObject(enemyHealth);

	TextObject c_att_s("characterStrength", f, "str");
	c_att_s.SetActionPerUpdate([&character,&c_att_s] {
		std::string textToShow = "Strength - " + std::to_string(character.GetAttribute(Creature::_strength));
		c_att_s.SetText(textToShow);
		});
	c_att_s.SetPosition({ 100,100 });
	game.AddGameObject(c_att_s);

	TextObject c_att_i("characterIntelligence", f, "int");
	c_att_i.SetActionPerUpdate([&character, &c_att_i] {
		std::string textToShow = "Intelligence - " + std::to_string(character.GetAttribute(Creature::_intelligence));
		c_att_i.SetText(textToShow);
		});
	c_att_i.SetPosition({ 100,150 });
	game.AddGameObject(c_att_i);

	TextObject c_att_a("characterAgility", f, "agi");
	c_att_a.SetActionPerUpdate([&character, &c_att_a] {
		std::string textToShow = "Agility - " + std::to_string(character.GetAttribute(Creature::_agility));
		c_att_a.SetText(textToShow);
		});
	c_att_a.SetPosition({ 100,200 });
	game.AddGameObject(c_att_a);

	TextObject e_att_s("enemyStrength", f, "str");
	e_att_s.SetActionPerUpdate([&enemy, &e_att_s] {
		std::string textToShow = "Strength - " + std::to_string(enemy.GetAttribute(Creature::_strength));
		e_att_s.SetText(textToShow);
		});
	e_att_s.SetPosition({ 1000,100 });
	game.AddGameObject(e_att_s);

	TextObject e_att_i("enemyIntelligence", f, "int");
	e_att_i.SetActionPerUpdate([&enemy, &e_att_i] {
		std::string textToShow = "Intelligence - " + std::to_string(enemy.GetAttribute(Creature::_intelligence));
		e_att_i.SetText(textToShow);
		});
	e_att_i.SetPosition({ 1000,150 });
	game.AddGameObject(e_att_i);


	TextObject e_att_a("enemyaAgility", f, "agi");
	e_att_a.SetActionPerUpdate([&enemy, &e_att_a] {
		std::string textToShow = "Agility - " + std::to_string(enemy.GetAttribute(Creature::_agility));
		e_att_a.SetText(textToShow);
		});
	e_att_a.SetPosition({ 1000,200 });
	game.AddGameObject(e_att_a);
#pragma endregion

#pragma endregion

#pragma region  Menu


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
			if (e.type == sf::Event::MouseButtonPressed) {
				std::cout << "x: " << sf::Mouse::getPosition(window).x << std::endl;
				std::cout << "y: " << sf::Mouse::getPosition(window).y << std::endl;
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