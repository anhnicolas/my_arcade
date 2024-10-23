/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** GraphicalModule
*/

#include "../../include/Graphics/AGraphicalModule.hpp"

AGraphicalModule::AGraphicalModule(const std::string type)
{
    _libraryType = type;
}

std::string AGraphicalModule::getLibraryType() const
{
    return _libraryType;
}

void AGraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>> &entities)
{
    (void)entities;
}

void AGraphicalModule::setisInGame(bool isInGame)
{
    _isInGame = isInGame;
}
