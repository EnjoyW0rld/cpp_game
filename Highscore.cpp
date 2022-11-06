#include "Highscore.hpp"


Highscore::Highscore(std::string fileName, std::string identifier, sf::Font& font,int spaceBetween) : GameObject(identifier),
fileName(fileName), font(font) {

	this->spaceBetween = spaceBetween;
	std::ifstream myFileRead(fileName);
	std::string line;
	while (std::getline(myFileRead, line)) {
		int tk = line.find(':');
		std::string name = line.substr(0, tk);
		int num = std::stoi(line.substr(++tk, line.length()));
		scores.push_back(std::pair<std::string, int>(name, num));
	}
	myFileRead.close();
	UpdateScoreText();
}

void Highscore::UpdateScoreText()
{
	if (scoreText.size() > 0) scoreText.erase(scoreText.begin(),scoreText.end());
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
	std::sort(scores.begin(), scores.end(),sortAlgorithm);
	if (scores.size() >= 10) scores.erase(scores.begin());

}
/// <summary>
/// Write current highscore to file specified in fileName
/// </summary>
void Highscore::WriteHighScore()
{
	std::ofstream myFileRead(fileName);
	for (int i = 0; i < scores.size(); i++)
	{
		myFileRead << scores[i].first << ":" << scores[i].second << std::endl;
	}
	myFileRead.close();
	SetSpaceBetween(spaceBetween);
}
void Highscore::AddScore(const std::pair<std::string, int> score)
{
	scores.push_back(score);
	SortScore();
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
void Highscore::HandleEvent(const sf::Event& ev, const sf::RenderWindow& window)
{
}
/*
void Highscore::SortMap()
{
	int length = scores.size();
	int* arr = new int[length];
	int c = 0;

	for (std::map<std::string, int>::iterator it = scores.begin(); it != scores.end(); ++it)
	{
		arr[c] = (*it).second;
		c++;
	}
	std::sort(arr, arr + length);
	std::map<std::string, int> sortedMap;
	for (int i = 0; i < length; i++)
	{
		//int is = scores["aaddd"];
		sortedMap.insert(std::pair<std::string, int>(FindName(arr[i]), arr[i]));
	}
	delete[] arr;
	//scores = sortedMap;
	scores = sortedMap;
}
std::string Highscore::FindName(int val)
{
	for (std::map<std::string, int>::iterator it = scores.begin(); it != scores.end(); ++it)
	{
		if ((*it).second == val) return (*it).first;
	}
	std::cout << "no value found" << std::endl;
	return " ";
}

std::map<std::string, int> Highscore::SortMapp()
{
	std::map<std::string, int> sortedMap;
	sortedMap.insert(*(scores.begin()));
	int toSortLength = scores.size();
	//for each member of to sort list
	for (int i = 1; i < toSortLength; i++)
	{
		// getting position that needs to be put in sorted array
		std::map<std::string, int>::iterator scoresIt = scores.begin();
		Iterate(scoresIt, i);
		std::pair<std::string, int> toSortPair = *scoresIt;
		//for each thing already in the sorted array
		for (int x = 0; x < sortedMap.size(); x++)
		{
			std::map<std::string, int>::iterator it = sortedMap.begin();
			Iterate(it, x);
			std::pair<std::string, int> pair = *it;
			if (toSortPair.second > pair.second) {

			}
			else {
				//sortedMap.insert()
			}
		}
	}
	return sortedMap;
}

void Highscore::Iterate(std::map<std::string, int>::iterator& it, int times)
{
	for (int i = 0; i < times; i++)
	{
		it++;
	}
}
*/