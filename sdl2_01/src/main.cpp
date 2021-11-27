#include "SDL.h"
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Config.h"

int main(int argc, char *argv[])
{
  
  config::load_config("conf.json");
  auto clogger = spdlog::stdout_color_mt("console");
  spdlog::set_default_logger(clogger);
  spdlog::set_level(spdlog::level::debug);
  spdlog::debug("{} started", config::app_name);
  
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow(
    "SDL2Test",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    640,
    480,
    0
  );

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  SDL_Delay(5000);

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}