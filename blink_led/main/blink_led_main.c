/* Blink LED example

*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

void BlinkLED2( void * pvParameters ){
    /* Block for 1000ms. */
    const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
    for(;;){
        // code led on/off
        gpio_set_level(GPIO_NUM_2, 1);
        vTaskDelay(xDelay);
        gpio_set_level(GPIO_NUM_2, 0);
        vTaskDelay(xDelay);
    }
}
void BlinkLED1( void * pvParameters ){
    /* Block for 1500ms. */
    const TickType_t xDelay = 1500 / portTICK_PERIOD_MS;
    for(;;){
        // code led on/off
        gpio_set_level(GPIO_NUM_16, 1);
        vTaskDelay(xDelay);
        gpio_set_level(GPIO_NUM_16, 0);
        vTaskDelay(xDelay);
    }
}

void app_main()
{
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_16,GPIO_MODE_OUTPUT);
    printf("Hello world!\n");
    xTaskCreate(BlinkLED2,"Blink led port 2", 1024*2,NULL,2,NULL);
    xTaskCreate(BlinkLED1,"Blink led port 16",1024*2,NULL,2,NULL);
}
