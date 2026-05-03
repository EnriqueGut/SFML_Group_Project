#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include <iostream>


Game::Game(): window(sf::VideoMode({400, 400}), "Title", sf::Style::Default)
{
    fps_max = 60.f;
    dt_min = 1.f / fps_max;
}


void Game::run()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.getElapsedTime().asSeconds();
       

        if (dt >= dt_min)
        {
            clock.restart();

            processEvents();
            update(dt);
            
            render();
        }
    }
}

void Game::processEvents()
{
    while (optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void Game::update(float dt)
{
    
    player.update(dt);

}

void Game::render()
{
    window.clear(sf::Color(64, 64, 64));
    map.draw(window);
    player.draw(window);
    window.display();
}

void Game::startBattle()
{
    
}

bool Game::inBattle()
{
    return false;
}

void Game::endBattle()
{
    
}
