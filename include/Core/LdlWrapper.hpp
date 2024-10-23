/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** LdlWrapper
*/

#pragma once

#include "../Graphics/AGraphicalModule.hpp"

class LdlWrapper {
    public:
        LdlWrapper() = default;
        LdlWrapper(const std::string& path);
        ~LdlWrapper() = default;

        void openLib(const std::string& path);
        template<typename T>
        T createLib(const std::string& name);
        void *getHandle() const;
        void closeLib();

    private:
        void *_handle = nullptr;
};
