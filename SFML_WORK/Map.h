#pragma once
#include "Player.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Window.hpp>

class Map
{
public:
    Map();
    void loadMap();
    void draw(sf::RenderWindow& window);
    bool isWalkable(sf::Vector2f position);
    int getTileAt(sf::Vector2f position);
    bool checkEncounterTile(sf::Vector2f position);
    sf::Vector2f getSpawnPoint();
private:
    int tileSize;
    std::vector<std::vector<int>> tileGrid;
    sf::Texture GRASS;
    int width;
    int height;
};
