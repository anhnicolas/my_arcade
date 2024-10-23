/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** starter
*/

#include "../../include/Core/CoreModule.hpp"
#include "../../include/Libs.hpp"

CoreModule::CoreModule() : _currentGamePath("lib/arcade_snake.so")
{
}

CoreModule::~CoreModule() {}

void CoreModule::loadGraphicalLibrary(const std::string &path, const std::string &func)
{
    std::cout << "Loading graphical library" << std::endl;
    try {
        _graphicalLib.openLib(path);
        _graphicalModule = _graphicalLib.createLib<std::shared_ptr<AGraphicalModule> >(func);
    } catch (const Error &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

std::shared_ptr<AGraphicalModule> &CoreModule::getGraphicalModule()
{
    return _graphicalModule;
}

LdlWrapper &CoreModule::getGraphicalLib()
{
    return _graphicalLib;
}

void CoreModule::changeGraphics(const std::string &path, const std::string &func)
{
    closeGraphicalLib();
    loadGraphicalLibrary(path, func);
}

void CoreModule::closeGraphicalLib()
{
    _graphicalLib.closeLib();
}

void CoreModule::loadGameLibrary(const std::string &path, const std::string &func)
{
    std::cout << "Loading game library" << std::endl;
    try {
        _gameLib.openLib(path);
        _gameModule = _gameLib.createLib<std::shared_ptr<AGameModule> >(func);
    } catch (const Error &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

std::shared_ptr<AGameModule> &CoreModule::getGameModule()
{
    return _gameModule;
}

LdlWrapper &CoreModule::getGameLib()
{
    return _gameLib;
}

void CoreModule::changeGame(const std::string &path, const std::string &func)
{
    closeGameLib();
    loadGameLibrary(path, func);
}

void CoreModule::closeGameLib()
{
    _gameLib.closeLib();
}

void CoreModule::checkFile(const std::string&path) const
{
    if (path.find(".so") == std::string::npos && path.find(".dylib") == std::string::npos) {
        std::cerr << "Invalid file" << std::endl;
        exit(84);
    }
}

void CoreModule::startGame()
{
    _graphicalModule->createWindow("Arcade");
    _graphicalModule->initAssets(_gameModule->initAllEntities());
    while (_graphicalModule->isWindowOpen()) {
        Input input = _graphicalModule->parseKeyboard();
        handleEvents(input);
        _gameModule->updateGame();
        _graphicalModule->showMap(_gameModule->getMap());
        _graphicalModule->displayWindow();
    }
    _graphicalModule->destroyWindow();
}

void CoreModule::handleEvents(const Input &input)
{
    if (input == Input::ESC) {
        _graphicalModule->destroyWindow();
    }
    if (input == Input::UP)
        _gameModule->catchInput(Input::UP);
    if (input == Input::DOWN)
        _gameModule->catchInput(Input::DOWN);
    if (input == Input::LEFT)
        _gameModule->catchInput(Input::LEFT);
    if (input == Input::RIGHT)
        _gameModule->catchInput(Input::RIGHT);
    if (input == Input::CHANGE_LIB) {
        std::cout << "Changing graphical library" << std::endl;
        _graphicalModule->destroyWindow();
        _libIndex = (_libIndex + 1) % _graphicalLibs.size();
        loadGraphicalLibrary(_graphicalLibs[_libIndex], "createLib");
        startGame();
    }
    if (input == Input::RELOAD) {
        loadGameLibrary(_currentGamePath, "createGame");
        _gameModule->setGameStatus(GameStatus::RUNNING);
    }
    (void)input;
}

void CoreModule::getLibraries()
{
    std::string directoryPath = "lib/";
    std::string extension = ".so";
    std::vector<std::string> libraryNames = {"sdl2", "sfml"};

    for (const auto &entry : std::filesystem::directory_iterator(directoryPath)) {
        if (entry.path().extension() == extension) {
            for (const auto &libName : libraryNames) {
                if (entry.path().string().find(libName) != std::string::npos)
                    _graphicalLibs.push_back(entry.path().string());
                else
                    _gameLibs.push_back(entry.path().string());
            }
        }
    }
}

std::string CoreModule::getCurrentGamePath() const
{
    return _currentGamePath;
}