//  Battle.cpp
//  Group_Project1
#include "Battle.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

using namespace std;

Battle::Battle() : actionSprite(actionTexture),playerBattleSprite(battleSprite), enemyBattleSprite(enemyBattle),menu(font),info(font)
{ 
    overlay.setSize({810.f, 810.f});
    overlay.setFillColor(sf::Color(0,0,0,150));
    
    actionTexture.loadFromFile("Assets/Objects/inventory_example.png");
    actionSprite.setTexture(actionTexture);
    actionSprite.setTextureRect(sf::IntRect({0,24}, {352, 96}));
    actionSprite.setPosition({55.f,550.f});
    actionSprite.setScale({2.f,2.f});
    
    
    battleSprite.loadFromFile("Assets/Characters/Basic Charakter Spritesheet.png");
    playerBattleSprite.setTexture(battleSprite);
    playerBattleSprite.setTextureRect(sf::IntRect({17,160},{16,16}));
    playerBattleSprite.setScale({20.f, 20.f});
    playerBattleSprite.setPosition({60.f, 200.f});

    enemyBattle.loadFromFile("Assets/Characters/Basic Charakter Spritesheet.png");
    enemyBattleSprite.setTexture(battleSprite);
    enemyBattleSprite.setTextureRect(sf::IntRect({17,112},{16,16}));
    enemyBattleSprite.setScale({20.f, 20.f});
    enemyBattleSprite.setPosition({400.f, 200.f});


    font.openFromFile("Assets/Font/PIXEARG_.TTF");

    menu.setString("A - Attack Enemy\nR - Run");
    menu.setCharacterSize(28);
    menu.setFillColor(sf::Color::White);
    menu.setPosition({90.f,565.f});

    info.setString("Be sure to defeat this enemy.");
    info.setCharacterSize(12);
    info.setFillColor(sf::Color::White);
    info.setPosition({90.f,640.f});

    heldKey = false;
}

void Battle::update(float dt, Player& player, Enemy& enemy)
{
    
    bool attackKeyNow = sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A);

    if (attackKeyNow && !heldKey)
    {
        playerAttack(player, enemy);

        if (!(enemy.getHp() <= 0))
        {
            enemyTurn(player, enemy);
        }
    }

    updateInfoText(player, enemy);

    heldKey = attackKeyNow;
 
}

void Battle::draw(sf::RenderWindow& window)
{
    window.draw(overlay);
    window.draw(actionSprite);
    window.draw(playerBattleSprite);
    window.draw(enemyBattleSprite);
    window.draw(menu);
    window.draw(info);
}

void Battle::playerAttack(Player& player, Enemy& enemy)
{
    int damage = player.getAttack() - enemy.getDefense();
    enemy.takeDamage(damage);

}

void Battle::enemyTurn(Player& player, Enemy& enemy)
{
    int damage = enemy.getAttack() - player.getDefense();
    player.takeDamge(damage);
}
void Battle::updateInfoText(Player& player, Enemy& enemy)
{
    int playerDamage = enemy.getAttack() - player.getDefense();
    int enemyDamage = player.getAttack() - enemy.getDefense();

    info.setString("Player attacks for " + to_string(enemyDamage) + " damage.\t\tEnemy attacks for " + to_string(playerDamage) + 
    " damage.\nEnemy HP: " + to_string(enemy.getHp()) + "\t\t\t\t\t\t\t  Player HP: " + to_string(player.getHp()) 
    + "/" + to_string(player.getMaxHp()));
}
bool Battle::enemyDefeated(Enemy& enemy)const
{
    if(enemy.getHp() == 0)
    {
        return true;
    }
    else
        return false;
    
}
