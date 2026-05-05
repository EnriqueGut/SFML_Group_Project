#pragma once
#include "Item.h"
#include <SFML/Graphics.hpp>
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
	//void takeDamge();
	//void useItem();
	void update(float dt);
	void draw(sf::RenderWindow& window)const;
private:
	int hp, maxHP, defense, attack;
	sf::RectangleShape shape;
};


