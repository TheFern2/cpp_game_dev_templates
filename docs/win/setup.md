## Guide to setup system for game development

This guide will be primarily focused on cross platform projects by leveraging cmake and visual c++. Normally I run cmake gui, and auto generate vs2019 projects. If you're looking for visual studio setup from within vs gui there are tons of youtube videos and documentation.

The advantage of this setup, is that you can work in cross platform with the same project relatively easy. Also the ability to spin up projects quickly without having to worry too much about setup is a good reason to have a good streamlined setup.

The main focus here will be x64 for just about everything, but steps should be similar for x86. I will not cover downloading vs2019, and cpp build tools you should be familiar with that already.

## Downloads

- cmake (download and install, check env path during setup)
- SFML (https://www.sfml-dev.org/download/sfml/2.5.1/)
- SDL2 (https://www.libsdl.org/download-2.0.php)
- SDL2_image (https://www.libsdl.org/projects/SDL_image/)
- jsoncpp (https://github.com/open-source-parsers/jsoncpp)
- spdlog (https://github.com/gabime/spdlog)

## SFML Setup

Download the latest Visual C++ version the 2017 64bit works with vs2019, and presumably vs2022 (untested). Unzip to a central location where you keep your libraries for c++.

I keep mine on `D:\libs\x64\` although most libraries ship with both x64 and x86 I tend to focus only on x64. You can ommit the x64, but just pay attention to env variables paths. I like to keep version numbers for reference. Cut or copy library to your library path. `D:\libs\x64\SFML-2.5.1`. Inside your library you will have bin, doc, examples, include, lib, and licenses.

Add a new environment variable, I prefer user variables, but if more than one person uses it for dev you might want system variables.

Variable: SFML_DIR
Value: D:\libs\x64\SFML-2.5.1\lib\cmake\SFML

SFML ships with a cmake config, so it is an easy setup, when you launch a project `find_package(SFML 2)` will be found due to this env variable.

## SDL2 Setup

Download the latest Visual C++ version, and unzip in same folder used for SFML. `D:\libs\x64\SDL2-2.0.16`, same as before you should see docs, include, and libs inside that directory.

Variable: SDL2_DIR
Value: D:\libs\x64\SDL2-2.0.16

SDL2 doesn't ship with a cmake config, so we need to create our own. Basically we want to tell cmakegui, where our libs and includes are located. Create a file named `D:\libs\x64\SDL2-2.0.16\sdl2-config.cmake`

```
set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2main.lib")
else ()
  set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2main.lib")
endif ()

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
```

## SDL2_image Setup

This process is similar to SDL2. Download the latest Visual C++ version, and unzip in same folder used for SFML. `D:\libs\x64\SDL2_image-2.0.5`.

Variable: SDL2_image_DIR
Value: D:\libs\x64\SDL2_image-2.0.5

Create a file named `D:\libs\x64\SDL2-2.0.16\sdl2_image-config.cmake`

```
set(SDL2_IMAGE_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  set(SDL2_IMAGE_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2_image.lib")
else ()
  set(SDL2_IMAGE_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2_image.lib")
endif ()

string(STRIP "${SDL2_IMAGE_LIBRARIES}" SDL2_IMAGE_LIBRARIES)
```

## jsoncpp

Jsoncpp is a lightweight library to read json files, which are used in the Config namespace. Download the zip from the repo. Then `cd` into the repo directory. You might need admin rights for installing on Program Files.

```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX="C:/Program Files (x86)/jsoncpp" -DCMAKE_BUILD_TYPE=Release -DJSONCPP_WITH_TESTS=OFF -DJSONCPP_WITH_POST_BUILD_UNITTEST=OFF ..
cmake --build . --target install
```

> Source: https://github.com/open-source-parsers/jsoncpp/issues/922

## spdlog

Spdlog is about the best logging library, I use it quite often at work. Download the zip from the repo. Then `cd` into the repo directory. You might need admin rights for installing on Program Files.

```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX="C:/Program Files (x86)/spdlog/" -DSPDLOG_BUILD_EXAMPLES=OFF -DSPDLOG_BUILD_BENCH=OFF -DSPDLOG_BUILD_TESTS=OFF ..
cmake --build . --target install
```

> Source: https://github.com/gabime/spdlog/issues/1131
