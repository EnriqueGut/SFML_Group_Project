#include <vector>
#include "Player.h"
//#include "Enemy.h"
#include "Map.h"
#include "Battle.h"

class Game
{
public:
    Game();
    void run();
    void processEvents();
    void update(float dt);
    void render();
    void startBattle();
    bool inBattle();
    void endBattle();
private:
    
    Player player;
    Map map;
    sf::RenderWindow window;
    float fps_max;
    float dt_min;
    //std::vector<Enemy> enemies;
    //Battle battle;
     
};
