#ifndef PINSTATE_H
#define PINSTATE_H

#pragma once

typedef struct { 
  uint8_t key;
  String value;
} constantDictionary;

class PinState {
public:
    PinState();
    ~PinState();
    void setPinState( String pin, int state );
    int getPinState(  String pin );
    void clear();

private:
    const constantDicitionary _pin_map[];
};

#endif
