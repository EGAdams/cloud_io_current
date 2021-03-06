#pragma once
//
//
//
#ifndef MODE_1_TIEBREAKER_H
#define MODE_1_TIEBREAKER_H
#include "Player.h"
#include "UNDO.h"
#include "POINT_LEDs.h"
#include "DigiFunctions.h"
#include "GameState.h"
#include "SERVE_LEDs.h"
#include "GAME_LEDs.h"
#include "SET_LEDs.h"
#include "MODE_1_WIN_SEQUENCES.h"

class Mode1TieBreaker {
public:
    Mode1TieBreaker( Player *player1, Player *player2, DigiFunctions *digiFunctions );
    ~Mode1TieBreaker();
    void tieBreaker();
    void setTieBreaker();
    void mode1TBButtonFunction();
    void mode1SetTBButtonFunction();
    void tieBreakEnable();
    void setTieBreakEnable();
    void tieLEDsOn();
    void tieLEDsOff();
    void endTieBreak();

    // from mode 1 score
    void mode1TBP1Games();
    void mode1TBP2Games();
    void mode1SetTBP2Games();
    void mode1SetTBP1Games();

    // from mode 1 win sequences
    // void p1TBSetWinSequence();
    // void p1SetWinSequence();
    // void p2TBSetWinSequence();
    // void p2SetWinSequence();

private:
    Player            *_player1;
    Player            *_player2;
    GameState         *_gameState;
    Undo              _undo;
    DigiFunctions     _digiFunctions;
    PointLeds         _pointLeds;
    GameLeds          _gameLeds;
    ServeLeds         _serveLeds;
    SetLeds           _setLeds;
    Mode1WinSequences _mode1WinSequences;
};

#endif
