#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;
const int LED_PIN1 = 5;
const int LED_PIN2 = 8;
const int LED_PIN3 = 11;
const int LED_PIN4 = 15;

int main() {
  stdio_init_all();
  gpio_init(BTN_PIN);
  gpio_init(LED_PIN1);
  gpio_init(LED_PIN2);
  gpio_init(LED_PIN3);
  gpio_init(LED_PIN4);

  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_set_dir(LED_PIN1, GPIO_OUT);
  gpio_set_dir(LED_PIN2, GPIO_OUT);
  gpio_set_dir(LED_PIN3, GPIO_OUT);
  gpio_set_dir(LED_PIN4, GPIO_OUT);
  
  gpio_pull_up(BTN_PIN);
  while (true) {
    // Use delay de 300 ms entre os estados! ok professor
      if (!gpio_get(BTN_PIN)) {
        gpio_put(LED_PIN1, true);
        sleep_ms(300);

        gpio_put(LED_PIN1, false);
        gpio_put(LED_PIN2, true);
        sleep_ms(300);
        gpio_put(LED_PIN2, false);
        gpio_put(LED_PIN3, true);
        sleep_ms(300);

        gpio_put(LED_PIN3, false);
        gpio_put(LED_PIN4, true);
        sleep_ms(300);
        
        gpio_put(LED_PIN4, false);
        while (!gpio_get(BTN_PIN)) {
          gpio_put(LED_PIN1, false);
          gpio_put(LED_PIN2, false);
          gpio_put(LED_PIN3, false);
          gpio_put(LED_PIN4, false);
        };
    }
  }
}