/* Mon 27 Apr 19:07:13 UTC 2026 */
/* tricolor-fade-uno-q.ino */

/* Sun 26 Apr 14:42:40 UTC 2026 */

#include <Arduino_RouterBridge.h>

int ledR = LED3_R;
int brightness = 0;
int fadeAmount = 5;

int mw_counter = 0;
int led_tri_color = 0;

void set_led3_color(int r, int g, int b) {
  analogWrite(LED3_R, r);
  analogWrite(LED3_G, g);
  analogWrite(LED3_B, b);
}

void throw_error(int error_code) {
  Monitor.print(error_code);
  while (-1)
    ;
}

void aw_loop() {
  analogWrite(ledR, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30);
}

void assign_ledR(int led_tri_color) {
  switch (led_tri_color) {
    case 0:
      ledR = LED3_R;
      return;
    case 1:
      ledR = LED3_G;
      return;
    case 2:
      ledR = LED3_B;
      return;
    default:
      ledR = LED3_R;
  }
}

void led_reselect() {
  led_tri_color++;
  if (led_tri_color > 2) {
    led_tri_color = 0;
  }
  assign_ledR(led_tri_color);
}

void handle_mwcount() {
  mw_counter++;
  if (mw_counter > (126 * 8)) {
    mw_counter = 0;
    Monitor.write(' ');
    Monitor.write('.');
    set_led3_color(0, 0, 0);
    led_reselect();
  }
}

void wide_loop() {
  aw_loop();
  handle_mwcount();
}

void setup_bridge() {
  if (!Bridge.begin()) {
    Serial.println("bad Bridge");
  }
}

void setup_monitor() {
  if (!Monitor.begin()) {
    Serial.println("bad Monitor");
  }
  Monitor.println(
    "    Hello Uno Q RGB Fade program ba224ef-9 Sun "
    "26-a");
}

void setup_bridge_provides() {
  if (!Bridge.provide("set_led3_color",
                      set_led3_color)) {
    throw_error(-33);
  }
}

void darken_RGB() {
  set_led3_color(0, 0, 0);
}

void setup() {
  delay(3000);
  setup_bridge();
  setup_monitor();
  setup_bridge_provides();
  darken_RGB();
  led_reselect();
}

void loop() {
  wide_loop();
  delay(30);
}

/* end. */
