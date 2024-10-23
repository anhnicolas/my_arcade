/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Error
*/

#pragma once

#include <iostream>

class Error : public std::exception {
    public:
        Error(std::string const message, int status = 84);

        const char *what() const noexcept;
        int getStatus() const;
        std::string getType() const;

    protected:
        std::string _message;
        int _status;
        std::string _type;
};

class FileError : public Error {
    public:
        FileError(std::string const message, int status = 84);
};

class NcursesError : public Error {
    public:
        NcursesError(std::string const message, int status = 84);
};

class SfmlError : public Error {
    public:
        SfmlError(std::string const message, int status = 84);
};

class Sdl2Error : public Error {
    public:
        Sdl2Error(std::string const message, int status = 84);
};
