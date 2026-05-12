//  Enemy.cpp
//  Group_Project1
#include "Enemy.h"
#include <string>
#include <iostream>

using namespace std;

Enemy::Enemy() : enemySprite(enemyTexture)
{
    loadSprite();
	name = " ";
	hp = 0;
	attack = 0;
	defense = 0;
	
}
Enemy::Enemy(string name, int hp, int attack, int defense) : enemySprite(enemyTexture)
{
    loadSprite();
	setName(name);
	setHp(hp);
	setAttack(attack);
	setDefense(defense);
}
void Enemy::display()const
{
	cout << getName() << "'s Info:\n";
	cout << "Health: " << getHp() << endl;
	cout << "Attack: " << getAttack() << endl;
	cout << "Defense: " << getDefense() << endl;
}

void Enemy::setName(string name)
{
    this->name = name;
}
void Enemy::setDefense(int defense)
{
	this->defense = defense;
}
void Enemy::setAttack(int attack)
{
	this->attack = attack;
}
void Enemy::setHp(int hp)
{
    this->hp = hp;
}
int Enemy::getAttack()const
{
	return attack;
}
int Enemy::getDefense()const
{
	return defense;
}
string Enemy::getName()const
{
	return name;
}
int Enemy::getHp()const
{
    return hp;
}
void Enemy::loadSprite()
{
    enemyTexture.loadFromFile("Assets/Characters/Basic Charakter Spritesheet.png");
    enemySprite.setTexture(enemyTexture);
    enemySprite.setTextureRect(sf::IntRect({17,112},{16,16}));
    enemySprite.setScale({3.f,3.f});
    enemySprite.setPosition({405.f,405.f});
}
void Enemy::takeDamage(int damage)
{
    if (damage <= 0)
    {
        damage = 0;
    }
    
    hp -= damage;

    if(hp <= 0)
    {
        hp = 0;
    }
}

sf::Vector2f Enemy::getPosition()const
{
    return enemySprite.getPosition();
}
void Enemy::draw(sf::RenderWindow& window)const
{
    window.draw(enemySprite);
}