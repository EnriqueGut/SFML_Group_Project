
#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Player::Player() : shape(Vector2f(10.f, 10.f))
{
    shape.setPosition({100.f,100.f});
    
    hp = 0;
    maxHP = 0;
    defense = 0;
    attack = 0;

}

Player::Player(int hp, int maxHP, int defense, int attack)
{
    RenderWindow window(VideoMode({ 640, 480 }), "Title", Style::Default);
    
    RectangleShape shape({ 10.f, 10.f });
    shape.setOrigin(shape.getGeometricCenter());
    shape.setPosition(window.getView().getSize() / 5.f);
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


/*
void Player::attackEnemy()
{

}
void Player::takeDamge()
{

}
void Player::useItem()
{

}
*/
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

