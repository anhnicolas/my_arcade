/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AGraphicalModule
*/

#pragma once

#include "IGraphicalModule.hpp"

class AGraphicalModule : public IGraphicalModule {
    public:
        AGraphicalModule(const std::string type);
        virtual ~AGraphicalModule() = default;

        // Window methods
        virtual void createWindow(const std::string& name, const std::vector<int>& size = {1920, 1080}) = 0;
        virtual void displayWindow() = 0;
        virtual void destroyWindow() = 0;
        virtual bool isWindowOpen() = 0;

        // Misc methods
        virtual Input parseKeyboard() = 0;
        virtual void showMap(const std::vector<std::vector<Tiles>>& map) = 0;
        virtual void initAssets(const std::vector<std::shared_ptr<AEntities>>& entities) = 0;
        std::string getLibraryType() const;
        void  setisInGame(bool isInGame);
    protected:
        std::string _libraryType;
        bool _isOpen = false;
        bool _isInGame = false;
        std::map<std::string, std::any> _assets;
};
