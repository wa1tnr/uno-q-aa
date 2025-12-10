/* Sun Dec  7 02:42:19 UTC 2025 */

#include <Arduino_RouterBridge.h>

const int pip = 0xFFF;

void lightLED() {
  /* neg. logic */
  digitalWrite(LED_BUILTIN, LOW);
}

void darkLED() {
  digitalWrite(LED_BUILTIN, HIGH);
}

void noop() {
  ;
}

void slower() {
  for (volatile int p = pip; p > 1; p--) {
    noop();
  }
}

void slowSome() {
  for (volatile int p = 0x3F; p > 1; p--) {
    delay(1);
  }
}

void brtBlink() {
  lightLED();
  slowSome();
  darkLED();
  delay(200);
}

void blink() {
  lightLED();
  slower();
  darkLED();
  delay(200);
}

void cdcAcmSetup() {
  Monitor.begin();
  delay(820);
  Monitor.println("");
}

void setup() {
  delay(1500);
  pinMode(LED_BUILTIN, OUTPUT);
  brtBlink();
  brtBlink();
  brtBlink();
  delay(8000);
  cdcAcmSetup();
  delay(1776);
  brtBlink();
  brtBlink();
}

void loop() {
  static unsigned long counter = 0;
  blink();
  blink();
  delay(9000);
  counter++;
  Monitor.print("    counter: ");
  Monitor.print(counter);
  Monitor.println("  Hello UNO Q");
}

/* end. */
