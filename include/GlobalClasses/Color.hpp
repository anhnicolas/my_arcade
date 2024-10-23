/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Color
*/

#pragma once

class Color {
    public:
        Color(int r = 255, int g = 255, int b = 255, int a = 255) : r(r), g(g), b(b), a(a) {}
        int r;
        int g;
        int b;
        int a;
};
