/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-robin.caboche
** File description:
** SDL2GraphicalModule
*/

#include "../../../include/Graphics/SDL2/Sdl2GraphicalModule.hpp"

Sdl2GraphicalModule::Sdl2GraphicalModule() : AGraphicalModule("SDL2")
{
}

void Sdl2GraphicalModule::createWindow(const std::string &name, const std::vector<int> &size)
{
    _window = SDL2Wrapper::SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size[0], size[1], SDL_WINDOW_SHOWN);
    _renderer = SDL2Wrapper::SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    _isOpen = true;
}

void Sdl2GraphicalModule::setWindowSize(const std::vector<int> &size)
{
    SDL2Wrapper::SDL_SetWindowSize(_window, size[0], size[1]);
}

void Sdl2GraphicalModule::setWindowTitle(const std::string &title)
{
    SDL2Wrapper::SDL_SetWindowTitle(_window, title);
}

void Sdl2GraphicalModule::displayWindow()
{
    SDL2Wrapper::SDL_RenderPresent(_renderer);
}

void Sdl2GraphicalModule::destroyWindow()
{
    SDL2Wrapper::SDL_DestroyRenderer(_renderer);
    SDL2Wrapper::SDL_DestroyWindow(_window);
}

bool Sdl2GraphicalModule::isWindowOpen()
{
    if (!_isOpen) {
        return false;
    }
    return true;
}

Input Sdl2GraphicalModule::parseKeyboard()
{
    while (SDL2Wrapper::SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT) {
            _isOpen = false;
            return Input::ESC;
        }
        if (_event.type == SDL_KEYDOWN) {
            switch (_event.key.keysym.sym) {
                case SDLK_z:
                    return Input::UP;
                case SDLK_q:
                    return Input::LEFT;
                case SDLK_s:
                    return Input::DOWN;
                case SDLK_d:
                    return Input::RIGHT;
                case SDLK_SPACE:
                    return Input::SPACE;
                case SDLK_ESCAPE:
                    _isOpen = false;
                    return Input::ESC;
                case SDLK_KP_ENTER:
                    return Input::ENTER;
                case SDLK_TAB:
                    return Input::MENU;
                case SDLK_RIGHT:
                    return Input::CHANGE_LIB;
                case SDLK_UP:
                    return Input::CHANGE_GAME;
                case SDLK_r:
                    return Input::RELOAD;
                default:
                    return Input::NONE;
            }
        }
    }
    return Input::NONE;
}

void Sdl2GraphicalModule::showMap(const std::vector<std::vector<Tiles>> &map)
{
    //initMap(map);
    SDL_RenderClear(_renderer);
    for (std::size_t y = 0; y < map.size(); y++) {
        for (std::size_t x = 0; x < map[y].size(); x++) {
            SDL_Rect rect;
            rect.x = x * _size;
            rect.y = y * _size;
            rect.w = _size;
            rect.h = _size;
            SDL2Wrapper::SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
            SDL2Wrapper::SDL_RenderFillRect(_renderer, &rect);
            SDL2Wrapper::SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);
            SDL2Wrapper::SDL_RenderDrawRect(_renderer, &rect);
            SDL2Wrapper::SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
        }
    }
    for (std::size_t y = 0; y < map.size(); y++) {
        for (std::size_t x = 0; x < map[y].size(); x++) {
            if (!map[y][x].getEntities().empty()) {
                for (auto &entity : map[y][x].getEntities()) {
                    std::pair<int, int> pos = entity->getPos();
                    SDL_Rect rect;
                    rect.x = pos.first * _size;
                    rect.y = pos.second * _size;
                    rect.w = _size;
                    rect.h = _size;
                    SDL_Texture *texture = std::any_cast<SDL_Texture*>(_assets[entity->imageToDisplay().first]);
                    SDL2Wrapper::SDL_RenderCopy(_renderer, texture, nullptr, &rect);
                }
            }
        }
    }
}

void Sdl2GraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>> &entities)
{
    for (auto &entity : entities) {
        auto [texturePath, ascii] = entity->imageToDisplay();
        SDL_Surface *surface = IMG_Load(texturePath.c_str());
        if (!surface) {
            std::cerr << "Failed to load image " << texturePath << ": " << IMG_GetError() << std::endl;
            continue;
        }
        SDL_Texture *texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        SDL2Wrapper::SDL_FreeSurface(surface);
        if (!texture) {
            std::cerr << "Failed to create texture from " << texturePath << ": " << SDL_GetError() << std::endl;
            continue;
        }
        _assets[texturePath] = texture;
    }
}

extern "C" std::shared_ptr<AGraphicalModule> createLib()
{
    return std::make_shared<Sdl2GraphicalModule>();
}
