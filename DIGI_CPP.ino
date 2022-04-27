// DIGI_CPP.cpp : Defines the entry point for the application.
//

#include "DIGI_CPP.h"
#include "DigiFunctions.h"
// #include "Serial.h"
// #include <SoftwareSerial.h>

using namespace std;

void setup() {
	// SerialObject Serial;
	DigiFunctions digiFunctions;
	Serial.begin( 9600 );
	Serial.println( "entering loop..." );
	digiFunctions.setup();
	digiFunctions.loop();
	return 0;
}
