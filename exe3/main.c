#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN1 = 28;
const int BTN_PIN2 = 26;
const int LED_PIN1 = 4;
const int LED_PIN2 = 6;

int main() {
  stdio_init_all();
  gpio_init(BTN_PIN1);
  gpio_init(BTN_PIN2);
  gpio_init(LED_PIN1);
  gpio_init(LED_PIN2);

  gpio_set_dir(BTN_PIN1, GPIO_IN);
  gpio_set_dir(BTN_PIN2, GPIO_IN);
  gpio_set_dir(LED_PIN1, GPIO_OUT);
  gpio_set_dir(LED_PIN2, GPIO_OUT);

  gpio_pull_up(BTN_PIN1);
  gpio_pull_up(BTN_PIN2);

  while (true) {
    if (!gpio_get(BTN_PIN1)) {
      printf("Botao 1\n");
      gpio_put(LED_PIN1, true);
      while (!gpio_get(BTN_PIN1)) {
      };
      gpio_put(LED_PIN1, false);
    }
    if (!gpio_get(BTN_PIN2)) {
      printf("Botao 2\n");
      gpio_put(LED_PIN2, true);
      while (!gpio_get(BTN_PIN2)) {
      };
      gpio_put(LED_PIN2, false);
    }
  }
}
