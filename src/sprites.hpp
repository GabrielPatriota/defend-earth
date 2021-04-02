#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Plane{
    private:
        sf::Vector2f scale = sf::Vector2f(1.2f, 1.2f);
    public:
        sf::Sprite plane;
        sf::Texture planetexture;

        Plane(){
            PlaneSet();
        }

        void PlaneSet()
        {
            planetexture.loadFromFile("sprites/plane.png");
            plane.setTexture(planetexture);
            plane.setScale(scale);
        }
};


class Ufo{
    private:
        sf::Vector2f scale = sf::Vector2f(1.2f, 1.2f);
    public:
        sf::Sprite ufo;
        sf::Texture ufotexture;

        Ufo(){
            UfoSet();
        }

        void UfoSet()
        {
            ufotexture.loadFromFile("sprites/ufo.png");
            ufo.setTexture(ufotexture);
            ufo.setScale(scale);
        }
};

class UfoShot{
    public:
        sf::Sprite ufoshot;
        sf::Texture ufoshottexture;

        UfoShot(){
            UfoShotSet();
        }

        void UfoShotSet()
        {
            ufoshottexture.loadFromFile("sprites/ufoshot.png");
            ufoshot.setTexture(ufoshottexture);
        }
};


class Shot{
    private:
        int radius = 5;
    public:
        sf::CircleShape shot;


        Shot(){
            ShotSet();
        }

        void ShotSet()
        {
            shot.setRadius(radius);
            shot.setFillColor(sf::Color::Yellow);
        }
};

class EndText{
    public:
        std::string text;
        sf::Font ubuntu;
        sf::Text endtext;
        EndText(){
            SetUbuntu();
        }

        void SetUbuntu()
        {
            ubuntu.loadFromFile("sprites/Ubuntu-Light.ttf");
            endtext.setFont(ubuntu);
            endtext.setString(text);
            endtext.setCharacterSize(20);
            endtext.setPosition(225, 325);
            endtext.setFillColor(sf::Color::Black);
        }
};