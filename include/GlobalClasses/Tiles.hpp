/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Tiles
*/

#pragma once

#include "Libs.hpp"

class AEntities;

class Tiles {
    public:
        Tiles(std::vector<std::shared_ptr<AEntities>> entities, int size = 1);

        std::vector<std::shared_ptr<AEntities>> getEntities() const;
        void setEntities(std::vector<std::shared_ptr<AEntities>> entities);
        int getSize() const;
        void setSize(int size);

    private:
        std::vector<std::shared_ptr<AEntities>> _entities;
        int _size;
        std::pair<int, int> _pos = {0, 0};
};
