/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGraphicalModule
*/

#pragma once

#include "Libs.hpp"

class IGraphicalModule {
    public:
        virtual ~IGraphicalModule() = default;

        // Window methods
        /**
         * @brief Create the window
         * @param name Title of the window
         * @param size Size of the window (default: 1920x1080)
        */
        virtual void createWindow(const std::string& name, const std::vector<int>& size) = 0;

        /**
         * @brief Display the window
        */
        virtual void displayWindow() = 0;

        /**
         * @brief Destroy the window
        */
        virtual void destroyWindow() = 0;


        // Misc methods

        /**
         * @brief Return true if the window is open, false otherwise
         * @return bool
        */
        virtual bool isWindowOpen() = 0;

        /**
         * @brief Parse keyboard events
        */
        virtual Input parseKeyboard() = 0;

        /**
         * @brief Display the map passed as parameter onto the window
         * @param map Map to show
        */
        virtual void showMap(const std::vector<std::vector<Tiles>>& map) = 0;

        /**
         * @brief Return the library type
         * @return std::string
        */
        virtual std::string getLibraryType() const = 0;

        /**
         * @brief Initialize the assets
         * @param map Map to initialize
        */
        virtual void initAssets(const std::vector<std::shared_ptr<AEntities>>& entities) = 0;
};
