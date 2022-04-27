#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#ifndef PLAYER_H
#define PLAYER_H
#include "Player.h"
#endif

#pragma once
#include <LiquidCrystal_I2C.h>
#include "ScoreBoard.h"

class ScoreBoard {
public:
    ScoreBoard( Player *player1, Player *player2, LiquidCrystal_I2C *lcdDisplay );
    void update();
    ~ScoreBoard();

private:
    Player *_player1;
    Player *_player2;
    LiquidCrystal_I2C *_lcd;
};

#endif