#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
/*#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode({ 640, 480 }), "Title", Style::Default);
    
    //create shape
    RectangleShape shape({ 10.f, 10.f });
    shape.setOrigin(shape.getGeometricCenter());
    shape.setPosition(window.getView().getSize() / 5.f);

    CircleShape cShape(10.f, 10);
    cShape.setPosition(window.getView().getSize() / 2.f);

    //Frame Rate limit
    float fps_max = 60.f;
    float dt_min = 1.f / fps_max;
    Clock clock;

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
                    float speed = 200.f;
                    float distance = speed * dt;
                    if (Keyboard::isKeyPressed(Keyboard::Scan::A))
                        shape.move({ -distance, 0.f });
                    if (Keyboard::isKeyPressed(Keyboard::Scan::D))
                        shape.move({ distance, 0.f });
                    if (Keyboard::isKeyPressed(Keyboard::Scan::W))
                        shape.move({0.f ,-distance});
                    if (Keyboard::isKeyPressed(Keyboard::Scan::S))
                        shape.move({ 0.f ,distance});
                     window.clear(Color(64,64,64));
                     window.draw(shape);
                     window.draw(cShape);
                     window.display();
        }
    }
	return 0;
}
*/