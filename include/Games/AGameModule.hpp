/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-elouan.rigomont
** File description:
** AGames
*/

#ifndef AGAMES_HPP_
#define AGAMES_HPP_

#include "Libs.hpp"
#include "IGameModule.hpp"

class AGameModule : public IGameModule {
    public:
        AGameModule(const std::string gameName);
        virtual ~AGameModule() = default;

        // score
        void setScore(int score);
        int getScore() const;
        void setHighScore(int score, std::string = "");
        std::map<std::string, int> getHighScore() const;

        // game status
        void setGameStatus(GameStatus status);
        GameStatus getGameStatus() const;
        std::vector<std::vector<Tiles>> getMap() const;

        // player
        std::string getPlayerName() const;
        void setPlayerName(std::string name);

        // game
        std::string getGameName() const;
        void setGameName(std::string name);
        virtual std::vector<std::shared_ptr<AEntities>> initAllEntities() const = 0;
        virtual void updateGame() = 0;

        // inputs
        virtual void catchInput(Input key = NONE) = 0;

    protected:
        std::vector<std::vector<Tiles>> _map = {};
        std::string _playerName = "";
        GameStatus _gameStatus = GameStatus::RUNNING;
        std::string _gameName = "";
        int _score = 0;
        std::map<std::string, int> _highScores = {};
};


#endif /* !AGAMES_HPP_ */
