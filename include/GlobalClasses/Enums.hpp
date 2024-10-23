/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** enums
*/

#ifndef ENUMS_HPP_
#define ENUMS_HPP_

enum Input {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ESC,
    ENTER,
    SPACE,
    MENU,
    CHANGE_LIB,
    CHANGE_GAME,
    RELOAD,
    NONE
};

enum Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST,
    STOP
};

enum GameStatus {
    OVER,
    WIN,
    PAUSE,
    RESTART,
    RUNNING
};

#endif /* !ENUMS_HPP_ */
