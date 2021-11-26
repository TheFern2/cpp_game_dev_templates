#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include <iostream>
#include <json/json.h>
#include <json/value.h>
#include <fstream>


std::string app_name;

bool load_config_file(std::string filename)
{
    Json::Value json;
    std::ifstream file(filename);

    if (file.good())
    {
        Json::Reader reader;
        reader.parse(file, json);

        app_name = json["app_name"].asString();

        return true;
    }
    else {
        spdlog::error("Configuration file not found");
        return false;
    }
}


int main()
{    
    load_config_file("conf.json");
    auto clogger = spdlog::stdout_color_mt("console");
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML template works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    spdlog::set_default_logger(clogger);
    spdlog::set_level(spdlog::level::debug);
    spdlog::debug("{} started", app_name);

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