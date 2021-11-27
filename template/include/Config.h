#pragma once

#include <iostream>

namespace config
{
    extern std::string app_name;

    bool load_config(std::string filename);
}