/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-robin.caboche
** File description:
** SnakeGameModule
*/

#include "../../../include/Games/Snake/SnakeGameModule.hpp"

// SnakeEntity
SnakeEntityHead::SnakeEntityHead(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

void SnakeEntityHead::setDirection(Direction direction)
{
    _direction = direction;
}

Direction SnakeEntityHead::getDirection() const
{
    return _direction;
}

EntityType SnakeEntityHead::getType() const
{
    return EntityType::PLAYER;
}

// SnakeEntity
SnakeEntityBody::SnakeEntityBody(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

void SnakeEntityBody::setDirection(Direction direction)
{
    _direction = direction;
}

Direction SnakeEntityBody::getDirection() const
{
    return _direction;
}

EntityType SnakeEntityBody::getType() const
{
    return EntityType::PLAYER;
}

// FoodEntity
FoodEntity::FoodEntity(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType FoodEntity::getType() const
{
    return EntityType::ITEM;
}

// WallEntity
WallEntity::WallEntity(double speed, std::pair<int, int> pos, std::string texturePath, ASCII ascii, std::string name)
    : AEntities(speed, pos, texturePath, ascii, name)
{
}

EntityType WallEntity::getType() const
{
    return EntityType::BLOCK;
}

// create Map of Tiles for Snake
std::vector<std::vector <Tiles>> SnakeGameModule::createMap(std::vector<std::shared_ptr<AEntities>> entities)
{
    for (int i = 0; i < _mapSize; i++) {
        std::vector<Tiles> line;
        for (int j = 0; j < _mapSize; j++) {
            std::vector<std::shared_ptr<AEntities>> entitiesAtPos;
            for (auto entity : entities) {
                if (entity->getPos() == std::make_pair(i, j)) {
                    entitiesAtPos.push_back(entity);
                }
            }
            line.push_back(Tiles(entitiesAtPos));
        }
        _map.push_back(line);
    }
    return _map;
}

// SnakeGameModule constructor
SnakeGameModule::SnakeGameModule(const std::string name)
    : AGameModule(name)
{
    _gameName = name;
    _entities = initAllEntities();
    _map = createMap(_entities);
    _direction = Direction::WEST;
    for (auto &entity : _entities) {
        if (entity->getName() == "food") {
            _food = entity;
        }
        if (entity->getName() == "snake_head" || entity->getName() == "snake_body") {
            _snake.push_back(entity);
        }
    }
    _lastUpdate = std::chrono::steady_clock::now();
    _updateInterval = std::chrono::milliseconds((450 / _snakeSpeed));
}

int SnakeGameModule::getSnakeSpeed()
{
    return _snakeSpeed;
}

void SnakeGameModule::setSnakeSpeed(int speed)
{
    _snakeSpeed = speed;
}

// Catch input for Snake
void SnakeGameModule::catchInput(Input key)
{
    std::pair<int, int> newPos;
    switch(key) {
        case Input::UP:
            _direction = Direction::NORTH;
            break;
        case Input::DOWN:
            _direction = Direction::SOUTH;
            break;
        case Input::LEFT:
            _direction = Direction::WEST;
            break;
        case Input::RIGHT:
            _direction = Direction::EAST;
            break;
        case Input::RELOAD:
            break;
        default:
            break;
    }
}

// Init all entities for Snake
std::vector<std::shared_ptr<AEntities>> SnakeGameModule::initAllEntities() const
{
    // Initialize the food entity
    FoodEntity foodEntity = FoodEntity(0, {4, 4}, "assets/food.png", ASCII('F', Color(255, 255, 255)), "food");

    // Initialize the snake head
    SnakeEntityHead snakeHead = SnakeEntityHead(0, {10, 10}, "assets/snakeHead.png", ASCII('c', Color(255, 255, 255)), "snake_head");

    // Initialize the snake body
    std::deque<std::shared_ptr<SnakeEntityBody>> snakeBody;
    for (int i = 0; i < initialSize; i++) {
        SnakeEntityBody bodySegment = SnakeEntityBody(0, {10 + i + 1, 10}, "assets/snakeBody.png", ASCII('o', Color(255, 255, 255)), "snake_body");
        snakeBody.push_back(std::make_shared<SnakeEntityBody>(bodySegment));
    }

    // Add all entities to the vector
    std::vector<std::shared_ptr<AEntities>> entities = {std::make_shared<FoodEntity>(foodEntity), std::make_shared<SnakeEntityHead>(snakeHead)};
    for (auto& bodySegment : snakeBody) {
        entities.push_back(bodySegment);
    }

    // Initialize the wall entities
    for (int i = 0; i < _mapSize; i++) {
        for (int j = 0; j < _mapSize; j++) {
            if (i == 0 || j == 0 || i == _mapSize - 1 || j == _mapSize - 1) {
                WallEntity wallEntity = WallEntity(0, {i, j}, "assets/wall.png", ASCII('X', Color(255, 255, 255)), "wall");
                entities.push_back(std::make_shared<WallEntity>(wallEntity));
            }
        }
    }
    return entities;
}

void SnakeGameModule::moveSnake(std::pair<int, int> newPos)
{
    // Store the old positions of the snake parts
    std::vector<std::pair<int, int>> oldPos;
    for (auto &snakePart : _snake) {
        oldPos.push_back(snakePart->getPos());
        _map[snakePart->getPos().second][snakePart->getPos().first].setEntities({});
    }
    // Move the head to the new position
    _snake[0]->setPos(newPos);
    _map[newPos.second][newPos.first].setEntities({_snake[0]});

    // Move each body part to the position of the part that was ahead of it
    for (std::size_t i = 1; i < _snake.size(); i++) {
        _snake[i]->setPos(oldPos[i - 1]);
        _map[oldPos[i - 1].second][oldPos[i - 1].first].setEntities({_snake[i]});
    }
}

void SnakeGameModule::updateGameLogic(Direction direction)
{
    // Initialize the direction of the snake's movement
    std::pair<int, int> dir;
    switch (direction) {
        case Direction::NORTH:
            dir = {0, -1};
            break;
        case Direction::SOUTH:
            dir = {0, 1};
            break;
        case Direction::WEST:
            dir = {-1, 0};
            break;
        case Direction::EAST:
            dir = {1, 0};
            break;
    }
    std::pair<int, int> newPos;
    for (auto& entity : _entities) {
        if (entity->getName() == "snake_head") {
            std::pair<int, int> headPos = entity->getPos();
            newPos = {headPos.first + dir.first, headPos.second + dir.second};
        }
    }
    eatFood();
    moveSnake(newPos);
    checkCollision(newPos);
}

void SnakeGameModule::checkCollision(std::pair<int, int> headPos)
{
    if (headPos.first == 0 || headPos.first == _mapSize - 1 || headPos.second == 0 || headPos.second == _mapSize - 1) {
        std::cout << "Game Over" << std::endl;
        _gameStatus = GameStatus::OVER;
    }
    for (auto& entity : _snake) {
        if (entity->getName() == "snake_body") {
            if (entity->getPos() == headPos) {
                std::cout << "Game Over" << std::endl;
                _gameStatus = GameStatus::OVER;
            }
        }
    }
}

void SnakeGameModule::eatFood()
{
    if (_snake[0]->getPos() == _food->getPos()) {
        _foodEaten++;
        std::cout << "Food Eaten: " << _foodEaten << std::endl;
        if (_foodEaten % 5 == 0) {
            _snakeSpeed++;
            _updateInterval = std::chrono::milliseconds((450 / _snakeSpeed));
        }
        //_map[entity->getPos().second][entity->getPos().first].setEntities({});

        auto newBodyPart = std::make_shared<SnakeEntityBody>(_snake[0]->getSpeed(), _snake.back()->getPos(),"assets/snakeBody.png", ASCII(' ', Color(0, 255, 0)), "snake_body");
        _snake.push_back(newBodyPart);
        _entities.push_back(newBodyPart);

        std::pair<int, int> newPos;
        do {
            newPos = {rand() % (_mapSize - 3) + 1, rand() % (_mapSize - 3) + 1};
        } while (!_map[newPos.second][newPos.first].getEntities().empty());

        _food->setPos(newPos);
        _map[newPos.second][newPos.first].setEntities({_food});
        _map[newBodyPart->getPos().second][newBodyPart->getPos().first].setEntities({newBodyPart});
    }
}

void SnakeGameModule::updateGame()
{
    if (_gameStatus == GameStatus::OVER) {
        return;
    }
    auto now = std::chrono::steady_clock::now();
    if (now - _lastUpdate >= _updateInterval) {
        updateGameLogic(_direction);
        _lastUpdate = now;
    }
}

extern "C" std::shared_ptr<AGameModule> createGame()
{
    return std::make_shared<SnakeGameModule>();
}
