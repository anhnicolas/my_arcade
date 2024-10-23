/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SfmlGraphicalModule
*/

#pragma once

#include "Graphics/AGraphicalModule.hpp"
#include "Entities/AEntities.hpp"
#include <SFML/Graphics.hpp>

class SfmlGraphicalModule : public AGraphicalModule {
    public:
        SfmlGraphicalModule();
        ~SfmlGraphicalModule() = default;

        // Window methods
        void createWindow(const std::string& name, const std::vector<int>& size);
        void setWindowSize(const std::vector<int>& size);
        void setWindowTitle(const std::string& title);
        void displayWindow();
        void destroyWindow();
        bool isWindowOpen();

        Input parseKeyboard();
        void showMap(const std::vector<std::vector<Tiles>>& map);
        void initAssets(const std::vector<std::shared_ptr<AEntities>>& entities);

        // create a map of Rectangles for the map of Tiles
        void initMap(const std::vector<std::vector<Tiles>>& map);
    private:
        sf::RenderWindow _window;
        sf::Event _event;
        std::map<std::string, sf::RectangleShape> _entitiesRect;
        std::vector<std::vector<sf::RectangleShape>> _tilesMap;
        float _size = 50;
};

extern "C" std::shared_ptr<AGraphicalModule> createLib();
