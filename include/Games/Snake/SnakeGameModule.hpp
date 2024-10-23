/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-robin.caboche
** File description:
** SnakeGameModule
*/

#ifndef SNAKEGAMEMODULE_HPP_
#define SNAKEGAMEMODULE_HPP_

#include "../AGameModule.hpp"
#include "../../Entities/AEntities.hpp"
#include <cmath>

class SnakeEntityHead : public AEntities {
    public:
        SnakeEntityHead(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);
        void setDirection(Direction direction);
        enum Direction getDirection() const;
        EntityType getType() const override;
    private:
        Direction _direction;
};

class SnakeEntityBody : public AEntities {
    public:
        SnakeEntityBody(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);
        void setDirection(Direction direction);
        enum Direction getDirection() const;
        EntityType getType() const override;
    private:
        Direction _direction;
};

class FoodEntity : public AEntities {
    public:
        FoodEntity(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);
        EntityType getType() const override;
};

class WallEntity : public AEntities {
    public:
        WallEntity(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name);
        EntityType getType() const override;
};

class SnakeGameModule : public AGameModule {
    public:
        SnakeGameModule(const std::string name = "Snake");
        ~SnakeGameModule() = default;

        void catchInput(Input key = NONE) override;
        std::vector<std::shared_ptr<AEntities>> initAllEntities() const override;
        void updateGame() override;

        //void addEntity(std::shared_ptr<AEntities> entity);
        std::vector<std::vector <Tiles>> createMap(std::vector<std::shared_ptr<AEntities>> entities);
        int getSnakeSpeed();
        void setSnakeSpeed(int speed);
        void updateGameLogic(Direction direction);
        void moveSnake(std::pair<int, int> newPos);
        void checkCollision(std::pair<int, int> headPos);
        void eatFood();

    private:
        std::vector<std::shared_ptr<AEntities>> _entities;
        std::vector<std::shared_ptr<AEntities>> _snake;
        std::shared_ptr<AEntities> _food;
        int initialSize = 3;
        int _mapSize = 20;
        std::chrono::steady_clock::time_point _lastUpdate;
        std::chrono::milliseconds _updateInterval;
        int _snakeSpeed = 2;
        int _foodEaten = 0;
        Direction _direction;
};

extern "C" std::shared_ptr<AGameModule> createGame();

#endif /* !SNAKEGAMEMODULE_HPP_ */
