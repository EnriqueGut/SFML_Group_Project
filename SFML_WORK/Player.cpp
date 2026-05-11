#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

Player::Player() : sprite(texture)
{
    loadSprite();
    hp = 0;
    maxHP = 0;
    defense = 0;
    attack = 0;
}

Player::Player(int hp, int maxHP, int defense, int attack) : sprite(texture)
{
    loadSprite();
    setHp(hp);
    setMaxHp(maxHP);
    setDefense(defense);
    setAttack(attack);
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


void Player::takeDamge(int damage)
{
    int actualDamage = damage - defense;

    if (actualDamage <= 0)
    {
        actualDamage = 0;
    }
    
    hp -= actualDamage;

    if(hp <= 0)
    {
        hp = 0;
    }

}

void Player::loadSprite() 
{    
    texture.loadFromFile("Assets/Characters/Basic Charakter Spritesheet.png");
    sprite.setTexture(texture);

    sprite.setTextureRect(sf::IntRect({17,16},{16,16}));

    sprite.setScale({3.f, 3.f});
    sprite.setPosition({100.f, 100.f});

}
void Player::update(float dt)
{

    float speed = 200.f;
    float distance = speed * dt;

    if (Keyboard::isKeyPressed(Keyboard::Scan::A))
    {
        sprite.move({ -distance, 0.f });
        sprite.setTextureRect(sf::IntRect({17,112},{16,16}));
    }
    else if (Keyboard::isKeyPressed(Keyboard::Scan::D))
    {
        sprite.move({ distance, 0.f });
        sprite.setTextureRect(sf::IntRect({17,160},{16,16}));
    }
    else if (Keyboard::isKeyPressed(Keyboard::Scan::W))
    {
        sprite.move({ 0.f ,-distance });
        sprite.setTextureRect(sf::IntRect({17,64},{16,16}));
    }
    else if (Keyboard::isKeyPressed(Keyboard::Scan::S))
    {
        sprite.move({ 0.f ,distance });
        sprite.setTextureRect(sf::IntRect({17,16},{17,17}));
    }
}
void Player::draw(RenderWindow& window)const
{
    window.draw(sprite);
}
