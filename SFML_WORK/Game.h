#pragma once
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "Battle.h"
#include <SFML/Audio.hpp>
class Game
{
public:
    Game();
    void run();
    void processEvents();
    void update(float dt, Player& player, Enemy& enemy);
    void render();
    void startBattle();
    void Music();

private:
    
    Player player;
    Enemy enemy;
    Map map;
    sf::RenderWindow window;
    float fps_max;
    float dt_min;
    sf::Music overworldMusic;
    bool inBattle = false;
    Battle battle;
     
};
