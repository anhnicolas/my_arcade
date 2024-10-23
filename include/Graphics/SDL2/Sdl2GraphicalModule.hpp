/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Sdl2GraphicalModule
*/

#pragma once

#include "Graphics/AGraphicalModule.hpp"
#include "Entities/AEntities.hpp"
#include "SDL2Wrapper.hpp"

class Sdl2GraphicalModule : public AGraphicalModule {
    public:
        Sdl2GraphicalModule();
        ~Sdl2GraphicalModule() = default;

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

    private:
        SDL_Window *_window = nullptr;
        SDL_Renderer *_renderer = nullptr;
        SDL_Event _event;
        float _size = 50;
};

extern "C" std::shared_ptr<AGraphicalModule> createLib();
