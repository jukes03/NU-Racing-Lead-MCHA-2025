// Sign-of-life code for Student Node
// Please copy/paste to your teensy workspace and flash to the Student Node Teensy 4.0 before returning.

#include <FastLED.h>
#define ONBOARD_LED_PIN 13
int heartBeat = 0;

void setup(void) {
}

void loop() {
  // Every 2s, Heartbeat
 EVERY_N_MILLISECONDS(2000){
   // Update LED output
   digitalWrite(ONBOARD_LED_PIN, heartBeat);
   // Invert current heartbeat state
   if (heartBeat == 0) {
     heartBeat = 1;
   } else {
     heartBeat = 0;
   }
 }
}