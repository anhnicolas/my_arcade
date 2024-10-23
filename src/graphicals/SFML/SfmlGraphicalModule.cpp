/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-robin.caboche
** File description:
** SfmlGraphicalModule
*/

#include "../../../include/Graphics/SFML/SfmlGraphicalModule.hpp"

SfmlGraphicalModule::SfmlGraphicalModule() : AGraphicalModule("SFML")
{
}

void SfmlGraphicalModule::createWindow(const std::string &name, const std::vector<int> &size)
{
    _window.create(sf::VideoMode(size[0], size[1]), name);
}

void SfmlGraphicalModule::setWindowSize(const std::vector<int> &size)
{
    _window.setSize(sf::Vector2u(size[0], size[1]));
}

void SfmlGraphicalModule::setWindowTitle(const std::string &title)
{
    _window.setTitle(title);
}

void SfmlGraphicalModule::displayWindow()
{
    _window.display();
}

void SfmlGraphicalModule::destroyWindow()
{
    _window.close();
}

bool SfmlGraphicalModule::isWindowOpen()
{
    return _window.isOpen();
}

Input SfmlGraphicalModule::parseKeyboard()
{
    if (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return Input::ESC;
        if (_event.type == sf::Event::KeyPressed) {
            switch (_event.key.code) {
                case sf::Keyboard::Z:
                    return Input::UP;
                case sf::Keyboard::Q:
                    return Input::LEFT;
                case sf::Keyboard::S:
                    return Input::DOWN;
                case sf::Keyboard::D:
                    return Input::RIGHT;
                case sf::Keyboard::Space:
                    return Input::SPACE;
                case sf::Keyboard::Escape:
                    return Input::ESC;
                case sf::Keyboard::Enter:
                    return Input::ENTER;
                case sf::Keyboard::Tab:
                    return Input::MENU;
                case sf::Keyboard::Right:
                    return Input::CHANGE_LIB;
                case sf::Keyboard::Up:
                    return Input::CHANGE_GAME;
                case sf::Keyboard::R:
                    return Input::RELOAD;
                default:
                    return Input::NONE;
            }
        }
    }
    return Input::NONE;
}

void SfmlGraphicalModule::showMap(const std::vector<std::vector<Tiles>> &map)
{
    _window.clear();
    initMap(map);
    // First draw all the tiles
    for (std::size_t y = 0; y < map.size(); y++) {
        for (std::size_t x = 0; x < map[y].size(); x++) {
            _tilesMap[y][x].setPosition(x * _size, y * _size);
            _tilesMap[y][x].setFillColor(sf::Color::White);
            _tilesMap[y][x].setOutlineColor(sf::Color::Red);
            _tilesMap[y][x].setOutlineThickness(1);
            _window.draw(_tilesMap[y][x]);
        }
    }
    // Then draw the entities
    for (std::size_t y = 0; y < map.size(); y++) {
        for (std::size_t x = 0; x < map[y].size(); x++) {
            if (!map[y][x].getEntities().empty()) {
                for (auto &entity : map[y][x].getEntities()) {
                    std::pair<int, int> pos = entity->getPos();
                    _entitiesRect[entity->getName()].setTexture(&std::any_cast<sf::Texture&>(_assets[entity->getName()]));
                    _entitiesRect[entity->getName()].setSize(sf::Vector2f(_size, _size));
                    _entitiesRect[entity->getName()].setPosition(pos.first * _size, pos.second * _size);
                    _window.draw(_entitiesRect[entity->getName()]);
                }
            }
        }
    }
}

void SfmlGraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>> &entities)
{
    for (auto &entity : entities) {
        auto [texturePath, ascii] = entity->imageToDisplay();
        sf::Texture texture;
        if (texture.loadFromFile(texturePath)) {
            _assets[entity->getName()] = std::move(texture);
            //sf::RectangleShape rect;
            //rect.setTexture(&std::any_cast<sf::Texture&>(_assets[entity->getName()]));
            //_entitiesRect[entity->getName()] = rect;
            // _entitiesRect[entity->getName()].setTexture(&std::any_cast<sf::Texture&>(_assets[entity->getName()]));
            // _entitiesRect[entity->getName()].setSize(sf::Vector2f(_size, _size));
        }
        // else
        //     throw FileError("Error while loading texture" + texturePath);
    }
}

void SfmlGraphicalModule::initMap(const std::vector<std::vector<Tiles>> &map)
{
    _tilesMap.resize(map.size());
    for (std::size_t y = 0; y < map.size(); y++) {
        _tilesMap[y].resize(map[y].size());
        for (std::size_t x = 0; x < map[y].size(); x++) {
            //sf::RectangleShape rect;
            //_tilesMap[y][x] = rect;
            _tilesMap[y][x].setSize(sf::Vector2f(_size, _size));
        }
    }
}

extern "C" std::shared_ptr<AGraphicalModule> createLib()
{
    return std::make_shared<SfmlGraphicalModule>();
}
