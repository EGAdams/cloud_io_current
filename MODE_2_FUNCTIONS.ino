#include <iostream>
#include <string>

#ifndef DIGI_V6_15_H_ONLY_
#define DIGI_V6_15_H_ONLY_
#include "DIGI_V6_15.h"
#endif

#ifndef Serial_h_
#define Serial_h_
#include "Serial.h"
#endif

#ifndef Player_h_
#define Player_h_
#include "Player.h"
#endif

#include "MODE_2_FUNCTIONS.h"

Mode2Functions::Mode2Functions( Player *player1, Player *player2, DigiFunctions *digiFunctions ):
                                 _gameState( digiFunctions->getGameState() ),
                                 _player1( player1 ),
                                 _player2( player2 ),
                                 _digiFunctions( digiFunctions ),
                                 _gameLeds(  player1, player2, digiFunctions ),
                                 _setLeds(   player1, player2, digiFunctions ),
                                 _pointLeds( player1, player2, digiFunctions ) {};

Mode2Functions::~Mode2Functions(){}

void Mode2Functions::m2Loop() {
    SerialObject Serial;
    _gameState->setNow( /* now = */ _digiFunctions->millis( 1 ));
    // unsigned long elapsed_time = now -  previous_time;
    // Serial.println( "elapsed_time: " + to_string( elapsed_time ));
    if ( _gameState->getNow() /* now */ - _gameState->getPreviousTime() /* previous_time */ >= 1000 /*10000*/ ) {
    // if ( true ) {
        int playerOneMode = _player1->getMode();
        switch ( _player1->getMode() ) {  /* modeP1 */

        // _player1 Points
        case 0:       
            _player1->incrementSetting(); // p1Setting++;
            _player1->setPoints( _player1->getSetting() ); //  p1Points = p1Setting;
            _pointLeds.updatePoints();  // UpdatePoints();
            if ( _player1->getSetting() > 3 ) /* p1Setting > 3 */ {
                _player1->setSetting( 0 );    // p1Setting = 0;
                _player1->setPoints( 0 );     // p1Points = 0;
                _player1->setMode( 1 );       // modeP1 = 1;
                // Serial.println( "_player1 set to mode 1" );
            }
            break;

        // _player1 Games
        case 1:
            _player1->incrementSetting();  // p1Setting++;
            _player1->setGames( _player1->getSetting() );  // p1Games = p1Setting;
            _gameLeds.updateGames();    // UpdateGames();
            if ( _player1->getSetting() > 6 /* p1Setting > 6 */ ) {
                _player1->setSetting( 0 );  // p1Setting = 0;
                _player1->setGames( 0 );    // p1Games = 0;
                _player1->setMode( 2 );     //   modeP1 = 2;
                // Serial.println( "_player1 set to mode 2" );
            }
            break;

        // _player1 Sets
        case 2:
            _player1->incrementSetting(); // p1Setting++;
            _player1->setSets( _player1->getSetting() );  // p1Sets = p1Setting;
            _setLeds.updateSets();      // UpdateSets();
            if ( _player1->getSetting() > 1  /* p1Setting > 1 */ ) {
                _player1->setSetting( 0 );   // p1Setting = 0;
                _player1->setSets( 0 );      // p1Sets = 0;
                _player1->setMode( 0 );      // modeP1 = 0;
            }
            break;
        }

        // _player2 Points
        switch ( _player2->getMode() /* modeP2 */ ) {
        case 0:
            // _player2->incrementSetting();     // p2Setting++;
            _player2->setPoints( _player2->incrementSetting() ); // p2Points = p2Setting;
            _pointLeds.updatePoints();      // UpdatePoints();
            if ( _player2->getSetting() > 4 /*  p2Setting > 4) */ ) {
                _player2->setSetting( 0 );  // p2Setting = 0;
                _player2->setPoints( 0 );   // p2Points = 0;
                _player2->setMode( 1 );     /* modeP2 = 1;  */ }
            break;

        // _player2 Games
        case 1:
            // p2Setting++;
            // p2Games = p2Setting;
            _player2->setGames( _player2->incrementSetting() ); // p2Games = p2Setting;
            _gameLeds.updateGames();            // UpdateGames();
            if ( _player2->getSetting() > 7 ) /* p2Setting > 7 */ {
                _player2->setSetting( 0 );    // p2Setting = 0;
                _player2->setGames( 0 );      // p2Games = 0;
                _player2->setMode( 2 );       // modeP2 = 2;
            }
            break;

        // _player2 Sets
        case 2:
            // p2Setting++;
            _player2->setSets( _player2->incrementSetting() ); // p2Sets = p2Setting;
            _setLeds.updateSets();  // UpdateSets();
            if (  _player2->getSetting() > 1    /* p2Setting > 1 */ ) {
                _player2->setSetting( 0 );      // p2Setting = 0;
                _player2->setSets(    0 );      // p2Sets = 0;
                _player2->setMode(    0 );      /* modeP2 = 0; */ }
        }
        _gameState->setPreviousTime( _gameState->getNow()); //  previous_time = now;
    } else {
        // Serial.println( "elapsed_time: " + to_string( elapsed_time ));
        Serial.println( "*** DID NOT ENTER BECAUSE NOT ENOUGH TIME HAS PASSED ***" );
    }
}

void Mode2Functions::m2PlayerButtons( int playerButton ) {
    SerialObject Serial;
    std::cout << "entering M2PlayerButtons()..." << std::endl;
    switch ( playerButton ) {
    case 0:
        break;

    case 1:
        Serial.println("p1 Set 1 LED");
        p1Setting++;
        std::cout << "p1Setting: " << p1Setting << std::endl;
        _gameState->setNow( _gameState->getNow() + 10000 ); // now = ( now + 10000 );
        //      Mode2Button1();
        break;

    case 2:
        Serial.println("p1 Set 2 LED");
        p1Setting--;
        std::cout << "p1Setting: " << p1Setting << std::endl;
        _gameState->setNow( _gameState->getNow() + 10000 ); // now = ( now + 10000 );
        //      Mode2Button2();
        break;

    case 3:
        Serial.println("p2 Set 2 LED");
        p2Setting++;
        _gameState->setNow( _gameState->getNow() + 10000 ); // now = ( now + 10000 );
        //      Mode2Button3();
        break;

    case 4:
        Serial.println("p2 Set 1 LED");
        p2Setting--;
        _gameState->setNow( _gameState->getNow() + 10000 ); // now = ( now + 10000 );
        //      Mode2Button4();
        break;
    }
    std::cout << "setting playerButton to zero." << std::endl;
    playerButton = 0;
}

//void Mode2Button1() {
//  if (p1s1 == 0) {
//    analogWrite(P1_SETS_LED1, HIGH);
//    p1s1 = 1;
//  }
//  else {
//    analogWrite(P1_SETS_LED1, LOW);
//    p1s1 = 0;
//  }
//}
//
//void Mode2Button2() {
//  if (p1s2 == 0) {
//    analogWrite(P1_SETS_LED2, HIGH);
//    p1s2 = 1;
//  }
//  else {
//    analogWrite(P1_SETS_LED2, LOW);
//    p1s2 = 0;
//  }
//}
//
//void Mode2Button3() {
//  if (p1s3 == 0) {
//    analogWrite(P2_SETS_LED2, HIGH);
//    p1s3 = 1;
//  }
//  else {
//    analogWrite(P2_SETS_LED2, LOW);
//    p1s3 = 0;
//  }
//}
//
//void Mode2Button4() {
//  if (p1s4 == 0) {
//    analogWrite(P2_SETS_LED1, HIGH);
//    p1s4 = 1;
//  }
//  else {
//    analogWrite(P2_SETS_LED1, LOW);
//    p1s4 = 0;
//  }
//}
