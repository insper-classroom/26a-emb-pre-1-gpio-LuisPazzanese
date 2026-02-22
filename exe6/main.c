#include <stdio.h>
#include "hardware/gpio.h"
#include "pico/stdlib.h"

const int FIRST_GPIO = 2;
const int BTN_PIN = 28;

int cnt = 0;
int last_btn = 1; // Button not pressed (pulled up)

int bits[10] = {
    0x3f,  // 0
    0x06,  // 1
    0x5b,  // 2
    0x4f,  // 3
    0x66,  // 4
    0x6d,  // 5
    0x7d,  // 6
    0x07,  // 7
    0x7f,  // 8
    0x67   // 9
};

void seven_seg_init() {
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }
}

void seven_seg_display() {
    int value = bits[cnt];
    for (int i = 0; i < 7; i++) {
        int bit = (value >> i) & 1;
        gpio_put(FIRST_GPIO + i, bit);
    }
}

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    seven_seg_init();
    seven_seg_display();

    while (true) {
        int btn = gpio_get(BTN_PIN);
        if (last_btn && !btn) {
            if (++cnt > 9) cnt = 0;
            seven_seg_display();
            printf("cnt: %d\n", cnt);
        }
        last_btn = btn;
        sleep_ms(10);
    }
}