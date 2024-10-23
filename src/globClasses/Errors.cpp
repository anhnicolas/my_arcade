/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Error
*/

#include "../../include/GlobalClasses/Errors.hpp"
#include "../../include/Libs.hpp"

Error::Error(std::string message, int status)
{
    _message = message;
    _status = status;
}

const char *Error::what() const noexcept
{
    return _message.c_str();
}

std::string Error::getType() const
{
    return _type;
}