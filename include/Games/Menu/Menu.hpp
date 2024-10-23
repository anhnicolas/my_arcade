/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu
*/

#pragma once

#include "../AGameModule.hpp"

class Menu : public AGameModule {
    public:
        Menu();
        ~Menu() = default;

        void catchInput(Input key = NONE);
        std::vector<std::shared_ptr<AEntities>> initAllEntities() const;
};

extern "C" std::shared_ptr<AGameModule> createGame();
