//  Battle.cpp
//  Group_Project1
#include "Battle.h"
#include "Player.h"
//#include "enemy.h"
#include <iostream>

using namespace std;

Battle::Battle() : actionSprite(actionTexture),playerBattleSprite(battleSprite),menu(font), info(font)
{ 
    overlay.setSize({810.f, 810.f});
    overlay.setFillColor(sf::Color(0,0,0,150));
    
    actionTexture.loadFromFile("C:/Users/eguti/CSS-2A/SFML_Group_Project/SFML_WORK/Assets/Objects/inventory_example.png");
    actionSprite.setTexture(actionTexture);
    actionSprite.setTextureRect(sf::IntRect({0,24}, {352, 96}));
    actionSprite.setPosition({55.f,550.f});
    actionSprite.setScale({2.f,2.f});
    
    
    battleSprite.loadFromFile("Assets/Characters/Basic Charakter Spritesheet.png");
    playerBattleSprite.setTexture(battleSprite);

    playerBattleSprite.setTextureRect(sf::IntRect({17,160},{16,16}));

    playerBattleSprite.setScale({20.f, 20.f});
    playerBattleSprite.setPosition({60.f, 200.f});


    font.openFromFile("Assets/Font/PIXEARG_.TTF");

    menu.setString("A - Attack Enemy\nR - Run");
    menu.setCharacterSize(28);
    menu.setFillColor(sf::Color::White);
    menu.setPosition({90.f,565.f});

    info.setString("Be sure to defeat this enemy.");
    info.setCharacterSize(12);
    info.setFillColor(sf::Color::White);
    info.setPosition({90.f,640.f});


}

void Battle::update(float dt, Player& player)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))
    {
        playerAttack(player);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::R))
    {
        //playerAttack(player);
    }
}

void Battle::draw(sf::RenderWindow& window)
{
    window.draw(overlay);
    //window.draw(battleActions);
    window.draw(actionSprite);
    window.draw(playerBattleSprite);
    window.draw(menu);
    window.draw(info);
}

void Battle::playerAttack(Player& player)
{
    int damage = player.getAttack();
    //enemy.takeDamage(damage);

    info.setString("Player attcked for " + to_string(damage) +
                    " damage.\nEnemy HP: " ); /*enemy.getHP()*/ 
    
}

void Battle::enemyTurn(Player& player)
{
    cout << "Enemy attacked!\n" 
        << "Player HP: " << player.getHp() << "/" << player.getMaxHp() << endl;
}  
      
bool Battle::enemyDefeated()const
{
    return false;
}
