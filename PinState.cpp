#include "PinState.h"

PinState::PinState(){}
PinState::~PinState(){}
int PinState::getPinState( String pin ){ return _pin_map[ pin ]; }
void PinState::setPinState( String pin, int state ){ _pin_map[ pin ] = state; }
void PinState::clear(){ Serial.prinln( "clearing map not defined yet..." ); }
