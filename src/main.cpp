/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** main
*/

#include "../include/Libs.hpp"
#include "../include/Core/ICoreModule.hpp"
#include "../include/Core/CoreModule.hpp"
#include "../include/Core/LdlWrapper.hpp"

static bool args_handler(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " [path to lib]" << std::endl;
        return false;
    }
    return true;
}

int main(int ac, char **av)
{
    if (!args_handler(ac, av))
        return 84;
    std::string lib_path = av[1];
    CoreModule core;
    core.checkFile(lib_path);
    core.loadGraphicalLibrary(lib_path, "createLib");
    core.loadGameLibrary(core.getCurrentGamePath(), "createGame");
    core.getLibraries();
    core.startGame();
    return 0;
}
