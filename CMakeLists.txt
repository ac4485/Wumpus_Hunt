cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(untitled main.cpp
        item/item.cpp
        item/item.h
        player/player.cpp
        player/player.h
        menu/menu.h
        menu/main_menu.cpp
        menu/main_menu.h
        menu/game_menu.cpp
        menu/game_menu.h
        map/map.cpp
        map/map.h
        event/event.cpp
        event/event.h
        event/treasure.cpp
        event/treasure.h
        alive/alive.cpp
        alive/alive.h
        item/weapon.cpp
        item/weapon.h
        event/monster.h
        event/monster.cpp)
