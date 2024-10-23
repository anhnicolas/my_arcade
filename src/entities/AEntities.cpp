/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-robin.caboche
** File description:
** AEntities
*/

#include "../include/Entities/AEntities.hpp"

AEntities::AEntities(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : _speed(speed), _pos(pos), _texturePath(texturePath), _ascii(ascii), _name(name)
{
}

double AEntities::getSpeed() const
{
    return _speed;
}

void AEntities::setSpeed(double speed)
{
    _speed = speed;
}

std::pair<int, int> AEntities::getPos() const
{
    return _pos;
}

void AEntities::setPos(std::pair<int, int> pos)
{
    _pos = pos;
}

std::pair<std::string, ASCII> AEntities::imageToDisplay() const
{
    return {_texturePath, _ascii};
}

std::string AEntities::getName() const
{
    return _name;
}

void AEntities::setName(std::string name)
{
    _name = name;
}
