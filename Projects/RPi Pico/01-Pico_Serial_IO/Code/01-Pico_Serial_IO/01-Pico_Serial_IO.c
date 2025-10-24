#include <stdio.h>
#include "pico/stdlib.h" 
#include "hardware/adc.h"
#include "pico/cyw43_arch.h" 
 

#define BTN_PIN 16
#define POT_PIN 26
#define POT_ADC_INPUT 0


int main()
{
    stdio_init_all();

    // Setup digital input
    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, false);         // Set as input
    gpio_set_pulls(BTN_PIN, true, false); // Enable pullup resistor

    //Setup analog input
    adc_init();
    adc_gpio_init(POT_PIN); //Reset GPIO pin
    adc_select_input(POT_ADC_INPUT); // Enable ADC Input 


    cyw43_arch_init();//Enable onboard LED
 
    
    while (true){
         bool buttonState = gpio_get(BTN_PIN); 
        
         uint16_t potReading = adc_read(); 
        
        printf("Button is %s. Pot is %d\n ", buttonState?"released":"pressed", potReading);

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, !buttonState); //Set onboard LED, on when button pressed
        sleep_ms(100);
    }
}
