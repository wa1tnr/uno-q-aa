/* Mon 27 Apr 18:59:02 UTC 2026 */
/* psketch-hh-fade.ino  rut-roh not same sketch */
/* side-project made 26 April - not intended sketch ;) */

#include <Arduino.h>

#include <Arduino_RouterBridge.h>

void thing_a() {
  Monitor.println("thing a");
}

void thing_c() {
  Monitor.println("thing c");
  Monitor.println("Sun Apr 26 07:44:42 PM UTC 2026");
}

void thing_q() {
  Monitor.println("thing q");
}

void thing_j() {
  Monitor.println("thing j");
}

int say_if_p(int rapid_iterations) {
  if (rapid_iterations > 102000) {
    rapid_iterations = 0;
    Monitor.print('s');
  }
  return rapid_iterations;
}

void timingston() {
  unsigned long ref_ms = millis();
  unsigned long ms_counted = 0;
  int p = 0;
  for (;;) {
    bool outcome = ms_counted > ref_ms + 1320;
    if (outcome) {
      return;
    }
    p = say_if_p(++p);
    ms_counted = millis();
  }
  Monitor.println("NEVER SEEN");
}

void setup() {
  delay(1200);
  Monitor.begin();

  bool p = true;

  if (p = 7) {
    thing_a();
  }

  if (p == 5) {
    thing_q();
  }

  if (5 == p) {
    thing_j();
  }

  bool w = p = 4;
  bool j = p == 19;
}

void loop() {
  delay(10);
  timingston();
  Monitor.println("");
  Monitor.print(" ");
  Monitor.write('j');
  Monitor.println("");
}
/* end. */
