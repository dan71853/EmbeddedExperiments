#include <stdio.h>
#include "pico/stdlib.h"

const uint LED_PIN = 16;

int main()
{
    stdio_init_all();

    //Setup LED pin as output
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN,true);

    while (true) {
        gpio_put(LED_PIN,true); 
        gpio_put(LED_PIN,false); 
    }
}
