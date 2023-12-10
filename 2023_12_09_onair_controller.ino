
// LIBRARIES


#include "MIDIUSB.h"


/////////////////////////////////////////////
// SETUP
void setup() {
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
//digitalWrite(2, LOW);
//digitalWrite(3, LOW);
//digitalWrite(4, LOW);
}

/////////////////////////////////////////////
// LOOP
void loop() {


  lights();
}


/////////////////////////////////////////////LIGHTS
void lights() {



midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();
    if (rx.header != 0) {
     

        if (rx.byte1 == 0x90 && rx.byte2 == 0x41 && rx.byte3 == 0x7F) {
        // Set the pin high to indicate that the specific note was received
        digitalWrite(2, HIGH);
      }
        if (rx.byte1 == 0x90 && rx.byte2 == 0x41 && rx.byte3 == 0x00) {
        // Set the pin high to indicate that the specific note was received
        digitalWrite(2, LOW);
      }

       if (rx.byte1 == 0x90 && rx.byte2 == 0x42 && rx.byte3 == 0x7F) {
        // Set the pin high to indicate that the specific note was received
        digitalWrite(3, HIGH);
      }
        if (rx.byte1 == 0x90 && rx.byte2 == 0x42 && rx.byte3 == 0x00) {
        // Set the pin high to indicate that the specific note was received
        digitalWrite(3, LOW);
      }


        if (rx.byte1 == 0x90 && rx.byte2 == 0x43 && rx.byte3 == 0x7F) {
        // Set the pin high to indicate that the specific note was received
        digitalWrite(4, HIGH);
      }
        if (rx.byte1 == 0x90 && rx.byte2 == 0x43 && rx.byte3 == 0x00) {
        // Set the pin high to indicate that the specific note was received
        digitalWrite(4, LOW);
      }
       



    }
    

  } while (rx.header != 0);

}


  

