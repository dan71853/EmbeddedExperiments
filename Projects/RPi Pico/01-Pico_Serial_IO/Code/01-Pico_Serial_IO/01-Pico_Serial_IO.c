#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

// UART defines
// By default the stdout UART is `uart0`, so we will use the second one
#define UART_ID uart1
#define BAUD_RATE 115200

// Use pins 4 and 5 for UART1
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define UART_TX_PIN 4
#define UART_RX_PIN 5

#define BTN_PIN 16
#include "pico/cyw43_arch.h"

int main()
{
    stdio_init_all();

    // Setup digital input
    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, false);         // Set as input
    gpio_set_pulls(BTN_PIN, true, false); // Enable pullup resistor


    cyw43_arch_init();




    while (true){
        volatile bool buttonState = gpio_get(BTN_PIN);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, buttonState);
        sleep_ms(50);
    }

    /*  Ignoring this example for now
    // Set up our UART
    uart_init(UART_ID, BAUD_RATE);
    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    // Use some the various UART functions to send out data
    // In a default system, printf will also output via the default UART

    // Send out a string, with CR/LF conversions
    uart_puts(UART_ID, " Hello, UART!\n");

    // For more examples of UART use see https://github.com/raspberrypi/pico-examples/tree/master/uart

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
    */
}
