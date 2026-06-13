/* Sat Jun 13 19:35:33 UTC 2026 */

/* no time taken Sat 13 June to re-test this copy. */

/* cross-out:blue an R G or B LED occasionally pips in
 * background while red LED listens for a toggle signal
 * from bridge */

#include <Arduino_RouterBridge.h>

const pin_size_t chosen_LED_reset = LED4_R - 1;
pin_size_t chosen_LED = LED4_R;

const unsigned long interval_lcl_ms = 1222;
unsigned long timer_a_lcl = 0;

void nopp() {
  ;
}

void advance_led_index() {
  pin_size_t led_count = 3;
  const pin_size_t chosen_LED_reset = LED4_R - 1;
  chosen_LED++;
  bool overflow =
    chosen_LED > chosen_LED_reset + led_count;
  if (overflow) {
    chosen_LED = chosen_LED_reset + 1;
  }
}

void t_cled_on() {
  bool STATE_ON = LOW;
  digitalWrite(chosen_LED, STATE_ON);
  delay(20);
}

void t_cled_off() {
  bool STATE_OFF = HIGH;
  digitalWrite(chosen_LED, STATE_OFF);
  delay(14123);
}

void blink_cled_once() {
  t_cled_on();
  t_cled_off();
  advance_led_index();
}

void setup_gpio() {
  bool STATE_OFF = HIGH;
  pin_size_t gp_pin = chosen_LED_reset;
  pin_size_t led_count = 3;
  for (; gp_pin < chosen_LED_reset + led_count;
       /*empty*/) {
    pinMode(++gp_pin, OUTPUT);
    digitalWrite(gp_pin, STATE_OFF);
  }
}

void update_timer_a_lcl() {
  timer_a_lcl = millis();
}

bool timer_compare_lcl() {
  bool compared =
    (millis() - timer_a_lcl) > interval_lcl_ms;
  if (!compared) {
    return false;
  }
  if (compared) {
    update_timer_a_lcl();
  }
  return true;
}

const pin_size_t LED4_B_nope = LED4_R;

void set_blue_led_state(bool state) {
  nopp();
}

void Xset_blue_led_state(bool state) {
  digitalWrite(LED4_B_nope, state ? LOW : HIGH);
  if (state) {
    digitalWrite(LED4_B_nope, state ? LOW : HIGH);
    delay(20);
    digitalWrite(LED4_B_nope, !state ? LOW : HIGH);
    return;
  }
}

void darken_blue_led() {
  digitalWrite(LED4_B_nope, HIGH);
}

void setup() {
  delay(2000);
  Serial.begin(9600);
  update_timer_a_lcl();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED4_B_nope, OUTPUT);
  darken_blue_led();
  Bridge.begin();
  Bridge.provide_safe("set_led_state", set_led_state);
  set_led_state(false);
  set_blue_led_state(true);

  /* blue LED is now lit */

  Serial.println(
    "    rev cea three - the illustrious program has "
    "begun.");
  setup_gpio();
}

void set_led_state(bool state) {
  digitalWrite(LED_BUILTIN, state ? LOW : HIGH);
}

void loop() {
  static bool state = false;
  bool compared = timer_compare_lcl();
  if (compared) {
    set_blue_led_state(state);
    state = !state;
    Serial.write('.');
  }
  blink_cled_once();
}

/* very early version of a merged program */
/* end. */
