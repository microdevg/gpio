/** Parpadeo simple de led GPIO_LED (GPI0 2 tiene un led integrado en  mi placa)
 * 
 *  @author German Velardez (germanvelardez16@gmail.com)
 * 
*/

#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"      // Necesario para configurar los delay. Recordemos que estamos en un entorno Freertos
#include "freertos/task.h"






#define LED_GPIO        (2)
#define LED_PERIODO     (250)   //mili seg



/**
 * Configuro el pin LED_GPIO como salida.
*/
static void configuracion_led(void ){

    gpio_reset_pin(LED_GPIO);
    /*Configura el led en modo salida */
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
}




void app_main(void)
{
    configuracion_led();
     bool toggle = false;
    while(1){
        vTaskDelay(LED_PERIODO / portTICK_PERIOD_MS);
        toggle = (toggle  == true)?     false:    true;
        gpio_set_level(LED_GPIO, toggle);
    }

}