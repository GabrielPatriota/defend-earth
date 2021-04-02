#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "sprites.hpp"

class CreateWindow{
    private:
        Plane plane;
        Ufo ufo;
        UfoShot ufoshot;
        Shot shot;
        EndText text;

        bool out2;
        bool fplane;
    public:
        int windowHeight = 450;
        int windowWidth = 650;
        std::string windowName = "Defend Earth";
        bool running;

        CreateWindow(){
            WindowCreate();
        }

        void WindowCreate()
        {
            sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), windowName, sf::Style::Close);
            window.setFramerateLimit(60);
            ufo.ufo.setPosition(windowWidth-31, ufo.ufo.getPosition().y);
            ufoshot.ufoshot.setPosition(ufo.ufo.getPosition().x, ufo.ufo.getPosition().y);

            while(window.isOpen()){
                sf::Event event;

                while(window.pollEvent(event)){

                    if(event.type == sf::Event::Closed){
                        window.close();
                    }
                }
                float distance = ufo.ufo.getPosition().y - plane.plane.getPosition().y;
                if(distance <= 10){
                    ufo.ufo.move(0.0f, 3.0f);
                } else {ufo.ufo.move(0.0f, -3.0f);}

                out2 = true;

                if(std::clock() % 100){
                    out2 = false;
                }

                if(!out2){
                    UfoShoot();
                } else {ufoshot.ufoshot.setPosition(ufo.ufo.getPosition().x, ufo.ufo.getPosition().y);}

                fplane = true;

                if(std::clock() % 50){
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                       fplane = false;
                    }
                }

                if(fplane){
                    Shoot();
                } else {FollowPlane();}

                if(distance <= 5 && distance >= 1){
                    ufo.ufo.move(0.0f, 0.0f);
                }

                Colision();

                plane.plane.setPosition(plane.plane.getPosition().x, sf::Mouse::getPosition(window).y);

                window.clear(sf::Color(44, 203, 228));
                window.draw(plane.plane);
                window.draw(ufo.ufo);
                window.draw(shot.shot);
                window.draw(ufoshot.ufoshot);
                window.draw(text.endtext);
                window.display();
            }
        }

        void UfoShoot()
        {
            ufoshot.ufoshot.move(-7.5f, 0.0f);
        }

        void Shoot()
        {
            shot.shot.move(6.6f, 0.0f);
        }

        void FollowPlane()
        {
            shot.shot.setPosition(plane.plane.getPosition().x, plane.plane.getPosition().y);
        }

        void Colision()
        {
            if(plane.plane.getGlobalBounds().intersects(ufoshot.ufoshot.getGlobalBounds())){
                text.text = "You Lost!";
                text.endtext.setString(text.text);
            } else if(shot.shot.getGlobalBounds().intersects(ufo.ufo.getGlobalBounds())){
                text.text = "You Won";
                text.endtext.setString(text.text);
            } else if(plane.plane.getGlobalBounds().intersects(ufo.ufo.getGlobalBounds())){
                text.text = "How did you do that?";
                text.endtext.setString(text.text);    
            } else if(shot.shot.getGlobalBounds().intersects(ufoshot.ufoshot.getGlobalBounds())){
                text.text = "Whoa!";
                text.endtext.setString(text.text);
                fplane = true;
                ufoshot.ufoshot.setPosition(ufo.ufo.getPosition().x, ufo.ufo.getPosition().y);
            }
        }
};