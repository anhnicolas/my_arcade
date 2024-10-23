/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IEntities
*/

#pragma once

#include "Libs.hpp"

enum EntityType {
    PLAYER,
    BLOCK,
    ITEM,
    EMPTY,
    BUTTON,
    BACKGROUND,
    TEXT
};

class IEntities {
    public:
        virtual ~IEntities() = default;

        virtual double getSpeed() const = 0;
        virtual void setSpeed(double speed) = 0;
        virtual std::pair<int, int> getPos() const = 0;
        virtual void setPos(std::pair<int, int> pos) = 0;
        virtual std::pair<std::string, ASCII> imageToDisplay() const = 0;
        virtual std::string getName() const = 0;
        virtual void setName(std::string name) = 0;
        virtual EntityType getType() const = 0;
};
