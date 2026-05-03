#pragma once
#include <string>
using namespace std;

class Item 
{
	public:
		Item();
		Item(string name, unsigned health, unsigned attack,
			unsigned defense, string description);
		void display()const;
		void setName(string name);
		string getName()const;
		void setHealth(unsigned health);
		unsigned getHealth()const;
		void setAttack(unsigned attack);
		unsigned getAttack()const;
		void setDefense(unsigned defense);
		unsigned getDefense()const;
		void setDescription(string description);
		string getDescription()const;
	private:
		string name, description;
		unsigned health, attack, defense;
};
