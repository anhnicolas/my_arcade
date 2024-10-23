/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu
*/

#include "../../../include/Games/Menu/Menu.hpp"

Menu::Menu() : AGameModule("Menu")
{
    // prepare all entities, set map, menu, infos, etc
}

void Menu::catchInput(Input key)
{
    if (key == Input::UP)
        std::cout << "UP" << std::endl;
    if (key == Input::DOWN)
        std::cout << "DOWN" << std::endl;
    if (key == Input::LEFT)
        std::cout << "LEFT" << std::endl;
    if (key == Input::RIGHT)
        std::cout << "RIGHT" << std::endl;
    if (key == Input::ENTER)
        std::cout << "ENTER" << std::endl;
}

std::vector<std::shared_ptr<AEntities>> Menu::initAllEntities() const
{
    std::vector<std::shared_ptr<AEntities>> entities;
    return entities;
}

extern "C" std::shared_ptr<AGameModule> createGame()
{
    return std::make_shared<Menu>();
}
