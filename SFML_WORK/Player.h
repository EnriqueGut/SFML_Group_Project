#pragma once
#include "Item.h"
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class Player
{
public:
    Player();
    Player(int hp, int maxHP, int defense, int attack);
    int getHp()const;
    int getMaxHp()const;
    int getDefense()const;
    int getAttack()const;
    void setHp(int hp);
    void setMaxHp(int maxHP);
    void setDefense(int defense);
    void setAttack(int attack);
    //void attackEnemy();
    void takeDamge(int damage);
    void loadSprite();
    void update(float dt);
    void draw(sf::RenderWindow& window)const;
private:
    int hp, maxHP, defense, attack;
    sf:: Sprite sprite;
    sf::Texture texture;
};



