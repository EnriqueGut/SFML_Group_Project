#include "item.h"
#include <string>
#include <iostream>

using namespace std;


Item::Item()
{
	name = "";
	health = 0;
	attack = 0;
	defense = 0;
	description = "";
}
Item::Item(string name, unsigned health,
	unsigned attack, unsigned defense, string description)
{
	setName(name);
	setHealth(health);
	setAttack(attack);
	setDefense(defense);
	setDescription(description);
}
void Item::display()const
{
	cout << getName() << "'s Info:\n";
	cout << "Health: " << getHealth() << endl;
	cout << "Attack: " << getAttack() << endl;
	cout << "Defense: " << getDefense() << endl;
	cout << "Description:\n" << getDescription() << endl;
}
void Item::setName(string name)
{
	this->name = name;
}
string Item::getName()const
{
	return name;
}
void Item::setHealth(unsigned health)
{
	this->health = health;
}
unsigned Item::getHealth()const
{
	return health;
}
void Item::setAttack(unsigned attack)
{
	this->attack = attack;
}
unsigned Item::getAttack()const
{
	return attack;
}
void Item::setDefense(unsigned defense)
{
	this->defense = defense;
}
unsigned Item::getDefense()const
{
	return defense;
}
void Item::setDescription(string description)
{
	this->description = description;
}
string Item::getDescription()const
{
	return description;
}
