#include "Map.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include <SFML/Window.hpp>

Map::Map()
{
    width = 10;
    height = 10;
    tileSize = 15;
    tileGrid = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
    GRASS = sf::Texture ("/Users/periwinkle12/Documents/School/Computer-science/Css-2A/Group_Project1/Assets/Tilesets/Grass.png");
}

void Map::loadMap()
{
    tileGrid = {{1, 5, 5, 5, 5, 5, 5, 5, 5, 2},
                {6, 0, 0, 0, 0, 0, 0, 0, 0, 8},
                {6, 0, 0, 0, 0, 0, 0, 0, 0, 8},
                {6, 0, 0, 0, 0, 0, 0, 0, 0, 8},
                {6, 0, 0, 0, 0, 0, 0, 0, 0, 8},
                {6, 0, 0, 0, 0, 0, 0, 0, 0, 8},
                {6, 0, 0, 0, 0, 0, 0, 0, 0, 8},
                {6, 0, 0, 0, 0, 0, 0, 0, 0, 8},
                {6, 0, 0, 0, 0, 0, 0, 0, 0, 8},
                {3, 7, 7, 7, 7, 7, 7, 7, 7, 4}};
    

}

void Map::draw(sf::RenderWindow& window)
{
    sf::Sprite sprite(GRASS),sprite1(GRASS), sprite2(GRASS), sprite3(GRASS), sprite4(GRASS), sprite5(GRASS), sprite6(GRASS), sprite7(GRASS), sprite8(GRASS);
    sprite.setTextureRect(sf::IntRect({14, 14}, {16, 16}));
    sprite1.setTextureRect(sf::IntRect({0, 0}, {14, 14}));
    sprite2.setTextureRect(sf::IntRect({30, 0}, {14, 14}));
    sprite3.setTextureRect(sf::IntRect({0, 30}, {14, 14}));
    sprite4.setTextureRect(sf::IntRect({30, 30}, {14, 14}));
    sprite5.setTextureRect(sf::IntRect({15, 0}, {16, 14}));
    sprite6.setTextureRect(sf::IntRect({0, 14}, {14, 16}));
    sprite7.setTextureRect(sf::IntRect({14, 30}, {16, 14}));
    sprite8.setTextureRect(sf::IntRect({30, 14}, {14, 16}));

    for(int y = 0; y < height ;y++)
    {
        for(int x = 0; x < width ;x++)
        {
            if(tileGrid[y][x] == 0)
            {
                sprite.setPosition({static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)});
                window.draw(sprite);
            }
            else if(tileGrid[y][x] == 1)
            {
                sprite1.setPosition({static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)});
                window.draw(sprite1);
            }
            else if(tileGrid[y][x] == 2)
            {
                sprite2.setPosition({static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)});
                window.draw(sprite2);
            }
            else if(tileGrid[y][x] == 3)
            {
                sprite3.setPosition({static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)});
                window.draw(sprite3);
            }
            else if(tileGrid[y][x] == 4)
            {
                sprite4.setPosition({static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)});
                window.draw(sprite4);
            }
            else if(tileGrid[y][x] == 5)
            {
                sprite5.setPosition({static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)});
                window.draw(sprite5);
            }
            else if(tileGrid[y][x] == 6)
            {
                sprite6.setPosition({static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)});
                window.draw(sprite6);
            }
            else if(tileGrid[y][x] == 7)
            {
                sprite7.setPosition({static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)});
                window.draw(sprite7);
            }
            else if(tileGrid[y][x] == 8)
            {
                sprite8.setPosition({static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)});
                window.draw(sprite8);
            }
        }
    }
}
/*
bool Map::isWalkable(sf::Vector2f position)
{
    
}

int Map::getTileAt(sf::Vector2f position)
{
    
}

bool Map::checkEncounterTile(sf::Vector2f position)
{
    
}

sf::Vector2f Map::getSpawnPoint()
{
    
}
*/
