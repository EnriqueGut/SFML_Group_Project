//  Battle.h
//  Group_Project1
#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

class Battle
{
    public:
        Battle();
        void update(float dt, Player& player, Enemy& enemy);
        void draw(sf::RenderWindow& window);
        
        void playerAttack(Player& player, Enemy& enemy); 
        
        void updateInfoText(Player& player, Enemy& enemy);

        void enemyTurn(Player& player, Enemy& enemy); 

        bool enemyDefeated(Enemy& enemy )const;

    private:

        bool heldKey;
        
        sf::RectangleShape overlay;
        sf::Texture actionTexture;
        sf::Sprite actionSprite;

        sf::Texture battleSprite;
        sf::Sprite playerBattleSprite;

        sf::Texture enemyBattle;
        sf::Sprite enemyBattleSprite;
        

        sf::Font font;
        sf::Text menu;
        sf::Text info;
};
