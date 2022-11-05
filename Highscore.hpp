#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "GameObject.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Highscore : public GameObject {
private:
	const std::string fileName;
	//std::vector<std::string> lines;
	std::vector<std::pair<std::string, int>> scores;
	std::vector<sf::Text> scoreText;
	sf::Font& font;
	static bool sortAlgorithm(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);
public:
	Highscore(std::string name,std::string identifier,sf::Font& font);
	~Highscore(void);
	int GetScoresLength() const;
	void SortScore();
	void WriteHighScore();
	void AddScore(const std::pair<std::string, int> score);
	void SetSpaceBetween(const int value);
	

	// Inherited via GameObject
	void Update() override;
	void Render(sf::RenderWindow& window) override;
	void HandleEvent(const sf::Event& ev, const sf::RenderWindow& window) override;

};