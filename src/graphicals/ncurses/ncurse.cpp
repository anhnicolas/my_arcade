/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-robin.caboche
** File description:
** ncurse
*/

#include "../../../include/Graphics/AGraphicalModule.hpp"
#include "../../../include/Graphics/Ncurses/NcursesWrapper.hpp"
#include "../../../include/Graphics/Ncurses/NcursesGraphicalModule.hpp"
#include <stdexcept>

NcursesGraphicalModule::NcursesGraphicalModule() : AGraphicalModule("Ncurses")
{
}

NcursesGraphicalModule::~NcursesGraphicalModule()
{
    if (_window)
        NcursesWrapper::n_endwin();
}

// NcursesWrapper implementation
WINDOW *NcursesWrapper::n_initscr()
{
    return initscr();
}

int NcursesWrapper::n_refresh()
{
    return refresh();
}

int NcursesWrapper::n_wrefresh(WINDOW *win)
{
    return wrefresh(win);
}

int NcursesWrapper::n_endwin()
{
    return endwin();
}

int NcursesWrapper::n_echo()
{
    return echo();
}

int NcursesWrapper::n_noecho()
{
    return noecho();
}

int NcursesWrapper::n_keypad(WINDOW *win, bool bf)
{
    return keypad(win, bf);
}

int NcursesWrapper::n_halfdelay(int tenths)
{
    return halfdelay(tenths);
}

int NcursesWrapper::n_clear()
{
    return clear();
}

int NcursesWrapper::n_wclear(WINDOW *win)
{
    return wclear(win);
}

int NcursesWrapper::n_wmove(WINDOW *win, int y, int x)
{
    return wmove(win, y, x);
}

void NcursesWrapper::n_getmaxyx(WINDOW *win, int *y, int *x)
{
    getmaxyx(win, *y, *x);
}

void NcursesWrapper::n_getyx(WINDOW *win, int *y, int *x)
{
    getyx(win, *y, *x);
}

int NcursesWrapper::n_mvprintw(int y, int x, std::string fmt)
{
    return mvprintw(y, x, fmt.c_str());
}

int NcursesWrapper::n_start_color()
{
    return start_color();
}

int NcursesWrapper::n_init_pair(short pair, short f, short b)
{
    return init_pair(pair, f, b);
}

int NcursesWrapper::n_init_color(short color, short r, short g, short b)
{
    return init_color(color, r, g, b);
}

int NcursesWrapper::n_getch()
{
    return getch();
}

// NcursesGraphicalModule implementation
void NcursesGraphicalModule::createWindow(const std::string& name, const std::vector<int>& size)
{
    _window = NcursesWrapper::n_initscr();
    (void)name;
    (void)size;
}

void NcursesGraphicalModule::initWindow(const std::string& name, const std::vector<int>& size)
{
    _window = NcursesWrapper::n_initscr();
    (void)name;
    (void)size;
}

void NcursesGraphicalModule::setWindowSize(const std::vector<int>& size)
{
    wresize(_window, size[0], size[1]);
    (void)size;
}

void NcursesGraphicalModule::setWindowTitle(const std::string& title)
{
    // Not implemented for ncurses
    (void)title;
}

void NcursesGraphicalModule::displayWindow()
{
    NcursesWrapper::n_wrefresh(_window);
}

void NcursesGraphicalModule::destroyWindow()
{
    NcursesWrapper::n_endwin();
    _window = nullptr;
}

bool NcursesGraphicalModule::isWindowOpen()
{
    return _window != nullptr;
}

Input NcursesGraphicalModule::parseKeyboard()
{
    int ch = NcursesWrapper::n_getch();
    switch(ch) {
        case KEY_UP:
            return Input::UP;
        case KEY_DOWN:
            return Input::DOWN;
        case KEY_LEFT:
            return Input::LEFT;
        case KEY_RIGHT:
            return Input::RIGHT;
        case KEY_ENTER:
            return Input::ENTER;
        // case KEY_
        //     return Input::ESC;
        case KEY_F0:
            return Input::SPACE;
        default:
            return Input::NONE;
    }
}

void NcursesGraphicalModule::showMap(const std::vector<std::vector<Tiles>>& map)
{
    // Not implemented for ncurses
    (void)map;
}

void NcursesGraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>>& entities)
{
    // Not implemented for ncurses
    (void)entities;
}

extern "C" std::shared_ptr<AGraphicalModule> createLib()
{
    return std::make_shared<NcursesGraphicalModule>();
}

