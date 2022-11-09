#include "Highscore.hpp"

Highscore::Highscore(const std::string fileName, std::string identifier, sf::Font& font, int spaceBetween) : GameObject(identifier),
fileName(fileName), font(font) {



	this->spaceBetween = spaceBetween;
	std::ifstream myFileRead(fileName);

	if (myFileRead.fail()) {
		std::ofstream file(fileName);
		file.close();
	}
	std::string line;
	while (std::getline(myFileRead, line)) {
		int tk;
		int num;
		std::string name;
		try
		{
			tk = line.find(':');
			name = line.substr(0, tk);
			num = std::stoi(line.substr(++tk, line.length()));
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			return;
		}
		scores.push_back(std::pair<std::string, int>(name, num));
	}
	myFileRead.close();
	UpdateScoreText();
}

void Highscore::UpdateScoreText()
{
	if (scoreText.size() > 0) scoreText.erase(scoreText.begin(), scoreText.end());
	for (int i = 0; i < scores.size(); i++)
	{
		std::string textToShow = scores[i].first + ":" + std::to_string(scores[i].second);
		sf::Text text(textToShow, font);
		text.setFillColor(sf::Color::White);
		scoreText.push_back(text);
	}
	SetSpaceBetween(spaceBetween);
}
Highscore::~Highscore(void) {}

int Highscore::GetScoresLength() const
{
	return scores.size();
}
bool Highscore::sortAlgorithm(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
	return a.second > b.second;
}
/// <summary>
/// Sort scores array
/// </summary>
void Highscore::SortScore()
{
	std::sort(scores.begin(), scores.end(), sortAlgorithm);
	while (scores.size() >= 6) {
		scores.erase(scores.end() - 1);
	}
}
/// <summary>
/// Write current highscore to file specified in fileName
/// </summary>
void Highscore::WriteHighScore()
{
	std::ofstream myFileRead(fileName);
	if (scores.size() > 0) {
		for (auto it = scores.begin(); it != scores.end(); it++)
		{
			myFileRead << (*it).first << ":" << (*it).second << std::endl;
		}
	}
	myFileRead.close();
}
void Highscore::AddScore(const std::pair<std::string, int> score)
{
	scores.push_back(score);
	SortScore();
	WriteHighScore();
	UpdateScoreText();
}
void Highscore::SetSpaceBetween(const int value)
{
	sf::Vector2f pos = transform.getPosition();
	spaceBetween = value;
	for (int i = 0; i < scoreText.size(); i++)
	{
		scoreText[i].setPosition({ pos.x,pos.y + (value * i) });
	}
}
void Highscore::Update()
{
}
void Highscore::Render(sf::RenderWindow& window)
{
	GameObject::Render(window);
	for (auto text = scoreText.begin(); text != scoreText.end(); text++)
	{
		window.draw((*text));
	}
}
void Highscore::EraseScore()
{
	scores.erase(scores.begin(), scores.end());
	WriteHighScore();
	UpdateScoreText();
}
void Highscore::HandleEvent(const sf::Event& ev, const sf::RenderWindow& window)
{
}