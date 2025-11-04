#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"

const uint LED_PIN = 16;

int main()
{
    stdio_init_all();

   volatile uint f_clk_sys = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_SYS);

    set_sys_clock_pll(1176, 7,7);

 f_clk_sys = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_SYS);


    //Setup LED pin as output
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN,true);

    while (true) {
        gpio_put(LED_PIN,true); 
        gpio_put(LED_PIN,false); 
    }
}
