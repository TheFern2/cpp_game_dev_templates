## Guide to setup system for game development

Setup is a bit more streamlined in linux due to package managers. I expect linux users to know how to install compilers, cmake, make, etc. That will not be covered in this guide. I will cover debian installs, but process should be similar for other distros. Use your package manager search function.

## Installs

- SFML (https://www.sfml-dev.org/tutorials/2.5/start-linux.php)
- SDL2 (https://www.libsdl.org/download-2.0.php)
- SDL2_image (https://www.libsdl.org/projects/SDL_image/)
- jsoncpp (https://github.com/open-source-parsers/jsoncpp)
- spdlog (https://github.com/gabime/spdlog)

```
sudo apt-get install libsfml-dev
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev
sudo apt-get install libjsoncpp-dev
sudo apt install libspdlog-dev
```

There's no need to set paths or anything like that in linux.