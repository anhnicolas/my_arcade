cmake_minimum_required(VERSION 3.25)
project(arcade)

set(CMAKE_CXX_STANDARD 20)

set(WARNING_FLAGS -Wall -W -g -g3 -std=c++20)
set(LDL_FLAGS -ldl)
set(NCURSES_FLAGS -lncurses)
set(SFML_FLAGS -lsfml-graphics -lsfml-window -lsfml-system)
set(SDL_FLAGS -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)

add_custom_target(create_lib_dir ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/lib
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include_directories(include)
include_directories(/usr/local/include/SDL2)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

set(global_src
    src/globClasses/Ascii.cpp
    src/globClasses/Tiles.cpp
)

# Core executable
set(core_src
    ${global_src}
    src/main.cpp
    src/core/Core.cpp
    src/core/Ldlwrapper.cpp
    src/graphicals/AGraphicalModule.cpp
    src/globClasses/Errors.cpp
)

add_executable(arcade ${core_src})
target_compile_options(arcade PRIVATE ${WARNING_FLAGS})
target_link_libraries(arcade ${LDL_FLAGS})

# Graphical libraries
set(ncurses_src
    ${global_src}
    src/graphicals/AGraphicalModule.cpp
    src/graphicals/ncurses/ncurse.cpp
)

set(sdl2_src
    ${global_src}
    src/graphicals/AGraphicalModule.cpp
    src/graphicals/sdl2/Sdl2GraphicalModule.cpp
    src/entities/AEntities.cpp
    src/graphicals/sdl2/Sdl2Wrapper.cpp
)

set(sfml_src
    ${global_src}
        src/graphicals/AGraphicalModule.cpp
    src/graphicals/SFML/SfmlGraphicalModule.cpp
    src/entities/AEntities.cpp
)

add_library(arcade_ncurses SHARED ${ncurses_src})
add_library(arcade_sdl2 SHARED ${sdl2_src})
add_library(arcade_sfml SHARED ${sfml_src})

target_compile_options(arcade_ncurses PRIVATE ${WARNING_FLAGS})
target_compile_options(arcade_sdl2 PRIVATE ${WARNING_FLAGS})
target_compile_options(arcade_sfml PRIVATE ${WARNING_FLAGS})

target_link_libraries(arcade_ncurses ${NCURSES_FLAGS})
target_link_libraries(arcade_sdl2 ${SDL_FLAGS})
target_link_libraries(arcade_sfml ${SFML_FLAGS})

set_target_properties(arcade_ncurses PROPERTIES PREFIX "")
set_target_properties(arcade_sdl2 PROPERTIES PREFIX "")
set_target_properties(arcade_sfml PROPERTIES PREFIX "")

# Games libraries
#set(nibbler_src
#    ${global_src}
#)

set(snake_src
    ${global_src}
    src/games/snake/SnakeGameModule.cpp
    src/games/AGameModule.cpp
    src/entities/AEntities.cpp
)

set(menu_src
    ${global_src}
    src/games/menu/Menu.cpp
    src/games/AGameModule.cpp
    src/entities/AEntities.cpp
    src/core/LdlWrapper.cpp
)

#add_library(arcade_nibbler SHARED ${nibbler_src})
add_library(arcade_snake SHARED ${snake_src})
#add_library(arcade_menu SHARED ${menu_src})

#set_target_properties(arcade_nibbler PROPERTIES PREFIX "")
set_target_properties(arcade_snake PROPERTIES PREFIX "")
#set_target_properties(arcade_menu PROPERTIES PREFIX "")
