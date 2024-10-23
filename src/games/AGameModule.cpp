/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** GameModule
*/

#include "Games/IGameModule.hpp"
#include "Games/AGameModule.hpp"

AGameModule::AGameModule(const std::string gameName)
{
    _gameName = gameName;
}

void AGameModule::setScore(int score)
{
    _score = score;
}

int AGameModule::getScore() const
{
    return _score;
}

void AGameModule::setHighScore(int score, std::string name)
{
    if (_highScores.empty())
        _highScores.insert({name, score});
    else {
        if (_highScores.find(name) != _highScores.end())
            _highScores[name] = score;
        else
            _highScores.insert({name, score});
    }
}

std::map<std::string, int> AGameModule::getHighScore() const
{
    return _highScores;
}

void AGameModule::setGameStatus(GameStatus status)
{
    _gameStatus = status;
}

GameStatus AGameModule::getGameStatus() const
{
    return _gameStatus;
}

std::vector<std::vector<Tiles>> AGameModule::getMap() const
{
    return _map;
}

std::string AGameModule::getPlayerName() const
{
    return _playerName;
}

void AGameModule::setPlayerName(std::string name)
{
    _playerName = name;
}

std::string AGameModule::getGameName() const
{
    return _gameName;
}

void AGameModule::setGameName(std::string name)
{
    _gameName = name;
}

void AGameModule::catchInput(Input key)
{
    (void)key;
}
