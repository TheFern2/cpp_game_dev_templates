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

    std::cout << "CLI Application started" << std::endl;

    return 0;
}