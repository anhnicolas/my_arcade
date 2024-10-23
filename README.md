# Arcade

## About

Arcade is the second project of the OOP module at Epitech (Oriented Object Programming). The goal of this project is to create a gaming platform that will allow the user to play games in a graphical interface. The user will be able to switch between games and graphical libraries at runtime. The project is divided into three parts:
- The core: The core is the main part of the project. It is the part that will manage the games and the graphical libraries. It will also be the part that will manage the user inputs.
- The games: The games are the games that the user will be able to play. The games will be loaded at runtime by the core.
- The graphical libraries: The graphical libraries are the libraries that will be used to display the games. The libraries will be loaded at runtime by the core.

## Collaborative Effort

We decided to work along with the following groups:
- [sacha.polerowicz@epitech.eu]()
- [jules.weishaus@epitech.eu]()
- [isaac.levy-piquet@epitech.eu]()
- [elouan.rigomont@epitech.eu]()
- [gianni.henriques@epitech.eu]()
- [augustin.piffeteau@epitech.eu]()

### Requirements

To compile the project you will need to have the following libraries installed:
- [CMake](https://cmake.org/)
- [Make](https://www.gnu.org/software/make/)

To run the project you will need to have at least the following libraries installed:
- [SFML](https://www.sfml-dev.org/)
- [SDL2](https://www.libsdl.org/)
- [NCURSES](https://invisible-island.net/ncurses/)

### Installation

First, you need to clone the repository:
```bash
git clone git@github.com:EpitechPromo2027/B-OOP-400-LIL-4-1-arcade-robin.caboche.git
```

Next you need to compile the project by running the following commands:
```bash
cmake .
make
```

### Usage
Then, to run the arcade project, you can execute the following command to start a SFML window for example:
```bash
./arcade ./lib/arcade_sfml.so
```

To play a game, the following keybinds are available:
- ZQSD : Move the player
- R : Restart the game
- ARROW RIGHT : Switch to the next graphical library
- ESCAPE : Close the window