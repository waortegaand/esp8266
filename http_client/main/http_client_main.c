#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_tls.h"

#include "esp_http_client.h"


//#include "nvs.h"

// Icludes of project
#include "http_request.h"
#include "wifi_connect.h"

static const char *TAG = "___wifi_station___";
/* */
static void http_test_task(void *pvParameters)
{
    https_rest_with_url_post();
    http_rest_with_url();
    // http_rest_with_hostname_path();
    // http_native_request();

    ESP_LOGI(TAG, "Finish http example");
    vTaskDelete(NULL);
}

void app_main(void)
{
    //ESP_ERROR_CHECK(nvs_flash_init());
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    ESP_ERROR_CHECK(esp_netif_init());
    //ESP_ERROR_CHECK(esp_event_loop_create_default());

    wifi_init_sta();
    ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
    /* */

    printf("\n\n\n_______________-PRUEBA---DE---ERROR-__________________\n\n\n");
    /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
     * Read "Establishing Wi-Fi or Ethernet Connection" section in
     * examples/protocols/README.md for more information about this function.
     */
    /*
    wifi_init_sta();
    ESP_LOGI(TAG, "Connected to AP, begin http example");
   */
    xTaskCreate(&http_test_task, "http_test_task", 1024*10, NULL, 5, NULL);
    printf("\n\n\n_______________-PRUEBA---DE---CONEXION-________________\n\n\n");
}
