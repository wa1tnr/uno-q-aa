/*
Mon 27 Apr 17:10:38 UTC 2026
*/

#include <Arduino_RouterBridge.h>

/* valid Arduino Uno Q in Arduino IDE 2.3.7
 * running on Debian AMD64 host PC with
 * no WiFi connection, only USB-C on
 * the Uno Q
 * ('adb devices' returns something) */

/* Wed 28 Jan 02:39:00 UTC 2026 */
/* Thu 15 Jan 00:17:21 UTC 2026 */

// const int someDelay = 9190;
const int someDelay = 919;

void progID() {
  delay(16123);
  Monitor.println("    the Program begins - formal aa bb"
                  "        27 Apr 2026 17:40z");
}

void setupMonitorPrinting() {
  Bridge.begin();
  delay(900);
  Monitor.begin();
  delay(900);
  progID();
  delay(900);
}

void blinkOnce() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(2);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(someDelay);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  setupMonitorPrinting();
}

void loop() {
  blinkOnce();
  delay(10);
}

/* end. */
