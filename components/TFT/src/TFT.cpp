/**
 * @file TFT.cpp
 * @author Locha Mesh Developers (contact@locha.io)
 * @brief 
 * @version 0.1
 * @date 2020-02-18
 * 
 * @copyright Copyright (c) 2020 Locha Mesh project developers
 * @license Apache 2.0, see LICENSE file for details
 * 
 */
#include "TFT.h"
#include "driver/gpio.h"
#include "driver/spi_common.h"
#include "driver/spi_master.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

spi_device_handle_t lcd;

int PARALLEL_LINES = 20;
/*
spi_bus_config_t bus_cfg = {};
bus_cfg.miso_io_num = TFT_MISO;
bus_cfg.mosi_io_num = TFT_MOSI;
bus_cfg.sclk_io_num = TFT_CLK;
bus_cfg.quadwp_io_num = -1;
bus_cfg.quadhd_io_num = -1;
bus_cfg.max_transfer_sz = PARALLEL_LINES * 320 * 2 + 8;
*/

esp_err_t tft_reset(gpio_num_t rst)
{
    esp_err_t res;
    res = gpio_set_level(rst, 0);
    vTaskDelay(100 / portTICK_RATE_MS);
    if (res != ESP_OK) {
        ESP_LOGE(__func__, "TFT reset: %s", esp_err_to_name(res));
        return res;
    }

    res = gpio_set_level(rst, 1);
    vTaskDelay(100 / portTICK_RATE_MS);
    if (res != ESP_OK) {
        ESP_LOGE(__func__, "TFT reset: %s", esp_err_to_name(res));
        return res;
    }
    return ESP_OK;
}

esp_err_t tft_init()
{
    esp_err_t res;

    res = gpio_set_direction(TFT_DC, GPIO_MODE_OUTPUT);
    if (res != ESP_OK) {
        ESP_LOGE(__func__, "Set TFT_DC output: %s", esp_err_to_name(res));
        return res;
    } else {
        ESP_LOGI(__func__, "Set TFT_DC output: %s", esp_err_to_name(res));
    }

    res = gpio_set_direction(TFT_RST, GPIO_MODE_OUTPUT);
    if (res != ESP_OK) {
        ESP_LOGE(__func__, "Set TFT_RST output: %s", esp_err_to_name(res));
        return res;
    } else {
        ESP_LOGI(__func__, "Set TFT_RST output: %s", esp_err_to_name(res));
    }

    res = gpio_set_direction(TFT_BCKL, GPIO_MODE_OUTPUT);
    if (res != ESP_OK) {
        ESP_LOGE(__func__, "Set TFT_BCKL output: %s", esp_err_to_name(res));
        return res;
    } else {
        ESP_LOGI(__func__, "Set TFT_BCKL output: %s", esp_err_to_name(res));
    }

    // LCD reset
    res = tft_reset(TFT_RST);
    if (res != ESP_OK) {
        ESP_LOGE(__func__, "TFT reset: %s", esp_err_to_name(res));
        return res;
    } else {
        ESP_LOGI(__func__, "TFT reset: %s", esp_err_to_name(res));
    }
    return ESP_OK;

    // LCD type: ILI9341
}
