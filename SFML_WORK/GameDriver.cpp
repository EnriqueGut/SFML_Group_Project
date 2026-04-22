#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode({ 640, 480 }), "Title", Style::Default);
    float fps_max = 60.f;
    float dt_min = 1.f / fps_max;
    
    Clock clock;
    Player player;

    while (window.isOpen())
    {
        float dt = clock.getElapsedTime().asSeconds();
       

        if (dt >= dt_min)
        {
            clock.restart();

            while (optional event = window.pollEvent())
            {
                if (event->is<Event::Closed>())
                    window.close();
            }
            player.update(dt);

            window.clear(Color(64, 64, 64));
            player.draw(window);
            window.display();
        }
    }
	return 0;
}
