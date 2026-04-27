/* Fri 24 Apr 17:21z runs fine Uno Q */

/* Thu 23 Apr 13:57:18 UTC 2026 */

#include <Arduino_RouterBridge.h>

void cdcAcmSetup() {
  Monitor.begin();
  delay(820);
  Monitor.println("");
}

void setup() {
  delay(1500);
  cdcAcmSetup();
  delay(1100);
  Monitor.println(
    "  Hello from this target board 23 April");
}

void loop() {
  static unsigned long counter = 0;
  delay(1200);
  counter++;
  Monitor.print("    counter: ");
  Monitor.print(counter);
}

/* end. */
