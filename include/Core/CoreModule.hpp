/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** CoreModule
*/

#pragma once

#include "LdlWrapper.hpp"
#include "ICoreModule.hpp"
#include "Graphics/AGraphicalModule.hpp"

class CoreModule : public ICoreModule {
    public:
        CoreModule();
        ~CoreModule();

        // Graphical libraries
        void loadGraphicalLibrary(const std::string& path, const std::string& func) override;
        std::shared_ptr<AGraphicalModule>& getGraphicalModule() override;
        LdlWrapper& getGraphicalLib() override;
        void changeGraphics(const std::string& path, const std::string& func) override;
        void closeGraphicalLib() override;

        // Game libraries
        void loadGameLibrary(const std::string& path, const std::string& func) override;
        std::shared_ptr<AGameModule>& getGameModule() override;
        LdlWrapper& getGameLib() override;
        void changeGame(const std::string& path, const std::string& func) override;
        void closeGameLib() override;

        // Misc
        void checkFile(const std::string& path) const override;
        void startGame() override;
        void handleEvents(const Input& input) override;
        void getLibraries();
        std::string getCurrentGamePath() const;

    private:
        std::shared_ptr<AGraphicalModule> _graphicalModule = nullptr;
        std::shared_ptr<AGameModule> _gameModule = nullptr;
        LdlWrapper _graphicalLib;
        LdlWrapper _gameLib;
        std::deque<std::string> _gameLibs = {};
        std::deque<std::string> _graphicalLibs = {};
        std::string _currentGamePath = "";
        size_t _libIndex = 0;
};
