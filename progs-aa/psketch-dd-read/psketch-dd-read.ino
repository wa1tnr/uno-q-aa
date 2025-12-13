/* Sat 13 Dec 19:32:59 UTC 2025 */

#include <Arduino_RouterBridge.h>

int p = 0;

/* Terminal Input Buffer for interpreter */
const byte maxtib = 16;
char tib[maxtib];
char namebuf[maxtib];
byte pos;

char ch;

byte reading() {
  if (!Monitor.available())
    return 1;
  ch = Monitor.read();
  Monitor.print(ch);
  if (ch == '\n')
    Monitor.print("\r");
  if (ch == '\n')
    return 0;
  if (ch == '\r') {
    return 1;
  }
  if (ch == ' ')
    return 0;
  if (ch == 'W') {
    Monitor.print("  walnut! it is a W  ");
    return 0;
  }
  if (ch == 'P') {
    Monitor.print("  proton! it is a P  ");
    return 0;
  }
  if (ch == 'J') {
    Monitor.print("  julius! it is a J  ");
    return 0;
  }
  if (pos < maxtib) {
    tib[pos++] = ch;
    tib[pos] = 0;
  }
  return 1;
}

void readword() {
  pos = 0;
  tib[0] = 0;
  while (reading())
    ;
  /* PRESERVE Monitor.print(tib); */
  Monitor.print(" ");
}

void setup() {
  delay(2900);
  while (!Monitor.begin())
    ;
  Monitor.print("  try: W P or J");
}

void loop() {
  static unsigned long counter = 0;
  readword();
  Monitor.print("  counter: ");
  Monitor.print(++counter);
  Monitor.print("  ");
}

/* end. */
