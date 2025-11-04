#pragma GCC optimize ("O0") //Used to disable optimization, helpful for debugging


#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"

const uint LED_PIN = 16;

int main()
{
    stdio_init_all();

 

    set_sys_clock_khz(24000, false);



    //Setup LED pin as output
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN,true);

    while (true) {
        gpio_put(LED_PIN,true); 
        gpio_put(LED_PIN,false); 
    }
}
