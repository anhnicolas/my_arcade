/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-robin.caboche
** File description:
** Tiles
*/

#include "../../include/GlobalClasses/Tiles.hpp"

Tiles::Tiles(std::vector<std::shared_ptr<AEntities>> entities, int size)
{
    _entities = entities;
    _size = size;
}

std::vector<std::shared_ptr<AEntities>> Tiles::getEntities() const
{
    return _entities;
}

void Tiles::setEntities(std::vector<std::shared_ptr<AEntities>> entities)
{
    _entities = entities;
}

int Tiles::getSize() const
{
    return _size;
}

void Tiles::setSize(int size)
{
    _size = size;
}
