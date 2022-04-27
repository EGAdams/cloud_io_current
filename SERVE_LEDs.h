#pragma once
//
//
//
#ifndef SERVE_LEDS_h
#define SERVE_LEDS_h

#include "GameState.h"
#include "DigiFunctions.h"

class ServeLeds {
public:
    ServeLeds( DigiFunctions *digiFunctions );
    ~ServeLeds();
    void updateServeLED();
    void serveSwitch();
    void setGameState( GameState *gameState );

private:
    GameState     *_gameState;
    DigiFunctions *_digiFunctions;
};

 #endif
