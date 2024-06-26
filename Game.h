#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"
#include "Ship.h"
#include <vector>
#include <string>

class Game {
private:
    Board player1Board;
    Board player2Board;
    Player player1;
    Player player2;
    std::vector<Ship*> fleetPlayer1;
    std::vector<Ship*> fleetPlayer2;
    int turn;
    bool gameOver;
    std::vector<std::pair<std::string, int>> ranking;

public:
    Game(const char* player1Name, const char* player2Name);
    ~Game();
    void play();
    void saveRanking(const char* file) const;
private:
    void initialiseFleet(std::vector<Ship*>& fleet);
    void playerTurn(Board& enemyBoard, std::vector<Ship*>& enemyFleet);
    void switchTurn();
    void checkGameOver();
    void updateRanking(const char* winnerName);
};

#endif
