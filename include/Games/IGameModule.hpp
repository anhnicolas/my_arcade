/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-elouan.rigomont
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

#include "Libs.hpp"

class IGameModule {
    public:
        virtual ~IGameModule() = default;

        // score
        virtual void setScore(int score) = 0;
        virtual int getScore() const = 0;
        virtual void setHighScore(int score, std::string = "") = 0;
        virtual std::map<std::string, int> getHighScore() const = 0;

        // game status
        virtual void setGameStatus(GameStatus status) = 0;
        virtual GameStatus getGameStatus() const = 0;
        virtual std::vector<std::vector<Tiles>> getMap() const = 0;

        // player
        virtual std::string getPlayerName() const = 0;
        virtual void setPlayerName(std::string name) = 0;

        // game
        virtual std::string getGameName() const = 0;
        virtual void setGameName(std::string name) = 0;
        virtual std::vector<std::shared_ptr<AEntities>> initAllEntities() const = 0;
        virtual void updateGame() = 0;

        // inputs
        virtual void catchInput(Input key = NONE) = 0;
};


#endif /* !IGAMES_HPP_ */
