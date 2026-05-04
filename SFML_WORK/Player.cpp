
#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Player::Player() : shape(Vector2f(10.f, 10.f))
{
    shape.setPosition({ 100.f,100.f });

    hp = 0;
    maxHP = 0;
    defense = 0;
    attack = 0;
    inventory[0] = Item("Item", 0, 0, 0, "This is an Item");
    inventory[1] = Item("Item2", 0, 0, 0, "This is an item2");
    inventory[2] = Item("Item3", 0, 0, 0, "This is an Item3");
}

Player::Player(int hp, int maxHP, int defense, int attack, Item inventory[])
{
    shape.setPosition({100.f,100.f});
    setHp(hp);
    setMaxHp(maxHP);
    setDefense(defense);
    setAttack(attack);
    setInventory(inventory);
}

int Player::getHp()const
{
    return hp;
}

int Player::getMaxHp()const
{
    return maxHP;
}

int Player::getDefense()const
{
    return defense;
}

int Player::getAttack()const
{
    return attack;
}
/*
Item Player::getInventory(int index)const
{
    return inventory[index];
}
*/
void Player::setHp(int hp)
{
    this->hp = hp;
}

void Player::setMaxHp(int maxHP)
{
    this->maxHP = maxHP;
}

void Player::setDefense(int defense)
{
    this->defense = defense;
}

void Player::setAttack(int attack)
{
    this->attack = attack;
}

void Player::setInventory(Item inventory[])
{
    for (int i = 0; i < 3; i++)
    {
        this->inventory[i] = inventory[i];
    }
}

/*
void Player::attackEnemy(Enemy Enemy)
{

}

void Player::takeDamge(Enemy enemy)
{
    hp - enemy.getAttack();
}
*/
void Player::useItem(Item item)
{
    if (hp + item.getHealth() <= maxHP)
    {
        hp = hp + item.getHealth();
    }
    else if (hp + item.getHealth() > maxHP)
    {
        hp = maxHP;
    }
    defense = defense + item.getDefense();
    attack = attack + item.getAttack();
}

void Player::update(float dt)
{

    float speed = 200.f;
    float distance = speed * dt;

    if (Keyboard::isKeyPressed(Keyboard::Scan::A))
        shape.move({ -distance, 0.f });
    if (Keyboard::isKeyPressed(Keyboard::Scan::D))
        shape.move({ distance, 0.f });
    if (Keyboard::isKeyPressed(Keyboard::Scan::W))
        shape.move({ 0.f ,-distance });
    if (Keyboard::isKeyPressed(Keyboard::Scan::S))
        shape.move({ 0.f ,distance });
}
void Player::draw(RenderWindow& window)const
{
    window.draw(shape);
}

