#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include <iostream>
#include "Config.h"

int main()
{    
    config::load_config("conf.json");
    auto clogger = spdlog::stdout_color_mt("console");
    spdlog::set_default_logger(clogger);
    spdlog::set_level(spdlog::level::debug);
    spdlog::debug("{} started", config::app_name);
    
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML template works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

#if defined(_WIN32)
#include <windows.h>
int APIENTRY WinMain(HINSTANCE, HINSTANCE, PSTR, int)
{
  return main();
}
#endif