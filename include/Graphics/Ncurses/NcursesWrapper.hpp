/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NcursesWrapper
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include "Libs.hpp"

class NcursesWrapper {
    public:
        NcursesWrapper() = default;
        ~NcursesWrapper() = default;

    static WINDOW *n_initscr();
    static int n_refresh();
    static int n_wrefresh(WINDOW *win);
    static int n_endwin();
    static int n_echo();
    static int n_noecho();
    static int n_keypad(WINDOW *win, bool bf);
    static int n_halfdelay(int tenths);
    static int n_clear();
    static int n_wclear(WINDOW *win);
    static int n_wmove(WINDOW *win, int y, int x);
    static void n_getmaxyx(WINDOW *win, int *y, int *x);
    static void n_getyx(WINDOW *win, int *y, int *x);
    static int n_mvprintw(int y, int x, std::string fmt);
    static int n_start_color();
    static int n_init_pair(short pair, short f, short b);
    static int n_init_color(short color, short r, short g, short b);
    static int n_getch();
};

#endif /* !NCURSES_HPP_ */
