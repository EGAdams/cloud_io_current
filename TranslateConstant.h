#ifndef TRANSLATECONSTANT_H
#define TRANSLATECONSTANT_H

#pragma once
typedef struct { 
  uint8_t key;
  String value;
} constantDictionary;

class TranslateConstant {
public:
    TranslateConstant();
    ~TranslateConstant();
    String get_translated_constant( int the_constant );
    String get_translated_digital_mode( int the_constant );

private:
    const constantDicitionary _map_constant_to_string[];
    const constantDictionary  _digital_mode_to_string[];
};

#endif
