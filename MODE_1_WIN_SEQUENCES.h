#pragma once
//
//
//
#ifndef MODE_1_WIN_SEQUENCES_H
#define MODE_1_WIN_SEQUENCES_H
#include "Player.h"
#include "DigiFunctions.h"
#include "UNDO.h"
#include "GameState.h"
#include "RESET.h"
// #include "MODE_1_TIEBREAKER.h"
#include "Serial.h"
#include "POINT_LEDs.h"
#include "GAME_LEDs.h"
#include "SET_LEDs.h"

class Mode1WinSequences {
public:
    Mode1WinSequences( Player *player1, Player *player2, DigiFunctions *digiFunctions );
    ~Mode1WinSequences();
    void p1GameWinSequence();
    void p1SetWinSequence();
    void p1MatchWinSequence();
    void p2GameWinSequence();
    void p2SetWinSequence();
    void p2MatchWinSequence();
    void p1TBGameWinSequence();
    void p2TBGameWinSequence();
    void p1TBSetWinSequence();
    void p2TBSetWinSequence();
    void p1SetTBWinSequence();
    void p2SetTBWinSequence();
    void p1TBMatchWinSequence();
    void p2TBMatchWinSequence();
    void tieLEDsOn();
    void tieLEDsOff();

private:
    Player          *_player1;
    Player          *_player2;
    Undo            _undo;
    DigiFunctions   _digiFunctions;
    GameState       *_gameState;
    PointLeds       _pointLeds;
    GameLeds        _gameLeds;
    SetLeds         _setLeds;
    Reset           _reset;
};

#endif
