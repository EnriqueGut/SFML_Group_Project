//  Battle.h
//  Group_Project1
#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
class Battle
{
    public:
        Battle();
        void update(float dt, Player& player);
        void draw(sf::RenderWindow& window);
        
        void playerAttack(Player& player); /*Enemy& Enemy*/
        
        
        void enemyTurn(Player& player); /*Enemy& Enemy*/

        bool enemyDefeated()const;

    private:
        
        sf::RectangleShape overlay;
        sf::Texture actionTexture;
        sf::Sprite actionSprite;
        sf::Texture battleSprite;
        sf::Sprite playerBattleSprite;

        /*
        sf::Textute enemyBattle;
        sf::Sprite enemyBattleSprite;
        */

        sf::Font font;
        sf::Text menu;
        sf::Text info;
};
