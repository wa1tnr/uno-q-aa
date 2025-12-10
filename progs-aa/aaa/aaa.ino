/* Sun Dec  7 02:14:11 AM UTC 2025 */

void lightLED() {
  digitalWrite(LED_BUILTIN, HIGH);
}

void darkLED() {
  digitalWrite(LED_BUILTIN, LOW);
}

void noop() {
  ;
}

const int pip = 0xFFF;

void slower() {
  for (volatile int p = pip; p > 1; p--) {
    noop();
  }
}

void blink() {
  darkLED();
  /* delay(3); */
  slower();
  lightLED(); delay(200);
}

void setup() {
  delay(1500);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  blink();
  blink();
  delay(9000);
}

/* end. */
