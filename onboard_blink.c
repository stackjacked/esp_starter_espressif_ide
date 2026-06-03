#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_GPIO 2

void app_main(void)
{
    // Configure the GPIO pin
    // gpio_reset_pin sets the pin to default state (input) and prepares it for use
    // It replaces the old gpio_pad_select_gpio + gpio_set_direction pattern
    gpio_reset_pin(BLINK_GPIO);
    
    // Set the pin as an output
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        // Turn the LED on (High level)
        gpio_set_level(BLINK_GPIO, 1);
        printf("LED is ON\n");
        
        // Wait for 1 second
        vTaskDelay(pdMS_TO_TICKS(1000));

        // Turn the LED off (Low level)
        gpio_set_level(BLINK_GPIO, 0);
        printf("LED is OFF\n");
        
        // Wait for 1 second
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}