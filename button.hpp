#pragma once

#include "gameObject.hpp"
#include <iostream>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>
#include "scene.hpp"

// typedef std::function<void()> buttonAction;

class Button : public GameObject {

    private:
        sf::Text text;
        sf::Font& font;
        sf::RectangleShape shape;
        std::string buttonText;
        std::function<void()> action;
    public:
        Button(std::string identifier, sf::Font& font, std::string buttonText, 
                sf::Vector2f size, sf::Color color);
        ~Button();

        void HandleEvent(const sf::Event& ev,const sf::RenderWindow& window) override;
        virtual void onClick();

        void Update() override;
        void Render(sf::RenderWindow& window) override;
        void setFontColour(const sf::Color c);
        void setButtonAction(std::function<void()> action);
        void setCharacterSize(const int size);
        void SetPosition(const sf::Vector2f position) override;
        void SetPosition(const int x,const int y);
        
};