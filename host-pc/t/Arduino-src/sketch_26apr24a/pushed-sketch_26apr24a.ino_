/* Fri 24 Apr 20:56:18 UTC 2026 */

#include <Arduino_RouterBridge.h>

void set_led3_color(int r, int g, int b) {
  analogWrite(LED3_R, r);
  analogWrite(LED3_G, g);
  analogWrite(LED3_B, b);
}

void throw_error(int error_code) {
  Monitor.println("");
  Monitor.println("not right");
  Monitor.print(error_code);
  while (-1)
    ;
}

int ledR = LED3_R;
int brightness = 0;
int fadeAmount = 5;

void aw_loop() {
  analogWrite(ledR, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30);
}

int mw_counter = 0;
int led_tri_color = 0;

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
  // was 8 now is 3:
  if (mw_counter > (126 * 3)) {
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
    Serial.println("cannot setup Bridge");
  }
}

void setup_monitor() {
  if (!Monitor.begin()) {
    Serial.println("cannot setup Monitor");
  }
  Monitor.println(
    "    Hello Uno Q RGB Fade program ba224ef-7");
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
  delay(2000);
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
