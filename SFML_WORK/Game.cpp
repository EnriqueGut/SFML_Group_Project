#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "battle.h"
#include <iostream>


Game::Game(): window(sf::VideoMode({810, 810}), "Title", sf::Style::Default)
{
    fps_max = 60.f;
    dt_min = 1.f / fps_max;
    player.setHp(100);
    player.setAttack(10);
    player.setMaxHp(100);
    player.setDefense(5);
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
    if (!inBattle)
    {
        player.update(dt);
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::B))
        {
            inBattle = true;
        }
    }

    else 
    {
        battle.update(dt, player);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))
        {
            battle.playerAttack(player);
        }
        
        if(battle.enemyDefeated())
        {
            inBattle = false;
        }
    }

}

void Game::render()
{
    window.clear(sf::Color(64, 64, 64));
    

    map.draw(window);
    player.draw(window);
    
    if (inBattle)
    {
        battle.draw(window);
    }
    
    window.display();
}
