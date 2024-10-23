/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Ascii
*/

#pragma once

#include "Color.hpp"

class ASCII {
    public:
        ASCII(char ascii, Color color) : _ascii(ascii), _color(color) {}

    private:
        char _ascii = 0;
        Color _color = Color(255, 255, 255);
};
