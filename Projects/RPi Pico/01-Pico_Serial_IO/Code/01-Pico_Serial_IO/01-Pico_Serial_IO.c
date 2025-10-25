// #pragma GCC optimize ("O0") //Used to disable optimization, helpful for debugging

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h" 


#define BTN_PIN 16
#define POT_PIN 26
#define POT_ADC_INPUT 0

volatile bool bouncing = false; //Only safe to read when bouncing = false

int64_t resetDebouncing(alarm_id_t id, __unused void *user_data){
    bouncing=false;
    return 0;
}


void buttonCallback(uint gpio, uint32_t events){
    if(bouncing==false){
        bouncing=true;
        add_alarm_in_ms(4, &resetDebouncing, NULL, false);
   
        uint16_t potReading = adc_read();

        printf("Button is Pressed, Pot is %d\n", potReading);
    }
}


int main(){
    stdio_init_all();

    // Setup digital input
    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, false);         // Set as input
    gpio_set_pulls(BTN_PIN, true, false); // Enable pullup resistor
    gpio_set_irq_enabled_with_callback(BTN_PIN, GPIO_IRQ_EDGE_FALL, true, &buttonCallback);

    // Setup analog input
    adc_init();
    adc_gpio_init(POT_PIN);          // Reset GPIO pin
    adc_select_input(POT_ADC_INPUT); // Enable ADC Input    

    while (true);
}
