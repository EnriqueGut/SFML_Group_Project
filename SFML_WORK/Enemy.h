#pragma once
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

class Enemy
{
public:
	Enemy();
    Enemy(string name, int hp, int attack, int defense);
	void display()const;
	void setName(string name);
	string getName()const;
	void setHp(int hp);
	int getHp()const;
	void setAttack(int attack);
	int getAttack()const;
	void setDefense(int defense);
	int getDefense()const;
    void loadSprite();
    void takeDamage(int damage);
	sf::Vector2f getPosition()const;
	void draw(sf::RenderWindow& window)const;
private:
	string name;
	int hp, attack, defense;
	
    sf:: Sprite enemySprite;
	sf::Texture enemyTexture;
	

};
