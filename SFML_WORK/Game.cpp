#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <cmath>


Game::Game(): window(sf::VideoMode({810, 810}), "Title", sf::Style::Default)
{
    fps_max = 60.f;
    dt_min = 1.f / fps_max;
    player.setHp(100);
    player.setAttack(10);
    player.setMaxHp(100);
    player.setDefense(5);

    enemy.setHp(100);
    enemy.setAttack(11);
    enemy.setDefense(2);
    Music();
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
            update(dt, player, enemy);
            
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

void Game::update(float dt, Player& player, Enemy& enemy)
{
    
    if (!inBattle)
    {
        player.update(dt);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::B) && 
        abs((player.getPosition().x - enemy.getPosition().x)) <= 70 && 
        abs((player.getPosition().y - enemy.getPosition().y)) <= 70) 
        {
            inBattle = true;
        }
    }

    else 
    {
        battle.update(dt, player, enemy);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::R))
        {
            inBattle = false;
        }
        if(battle.enemyDefeated(enemy))
        {
            inBattle = false;
        }

    }

}

void Game::render()
{
    window.clear(sf::Color(64, 64, 64));
    
    
    map.draw(window);
    if(enemy.getHp() > 0)
    {
        enemy.draw(window);
    }
    //enemy.draw(window);
    player.draw(window);
    
    if (inBattle)
    {
        battle.draw(window);
    }
    
    window.display();
}

void Game::Music()
{
    
    if(!overworldMusic.openFromFile("C:/Users/eguti/CSS-2A/SFML_Group_Project/SFML_WORK/Music/Idkrickysoverworldsong.ogg"))
    {
        std::cout << "Failed to load music\n";
    }

    overworldMusic.play();
    
}
