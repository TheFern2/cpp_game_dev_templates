#include <json/json.h>
#include <json/value.h>
#include <fstream>
#include <atomic>
#include "spdlog/spdlog.h"
#include "Config.h"

namespace config
{
    std::string app_name = "";
}

bool config::load_config(std::string filename)
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