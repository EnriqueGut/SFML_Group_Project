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
    void update(float dt);
    void render();
    void startBattle();
    void Music();

private:
    
    Player player;
    Map map;
    sf::RenderWindow window;
    float fps_max;
    float dt_min;
    sf::Music overworldMusic;
    //std::vector<Enemy> enemies;
    bool inBattle = false;
    Battle battle;
     
};
