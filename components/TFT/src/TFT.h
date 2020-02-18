/**
 * @file TFT.h
 * @author Locha Mesh Developers (contact@locha.io)
 * @brief 
 * @version 0.1
 * @date 2020-02-18
 * 
 * @copyright Copyright (c) 2020 Locha Mesh project developers
 * @license Apache 2.0, see LICENSE file for details
 * 
 */
#ifndef TFT_H
#define TFT_H

#include "esp_err.h"

#define TFT_MISO 25             // MISO
#define TFT_MOSI 23             // MOSI
#define TFT_CLK  19             // Clock
#define TFT_CS   22             //
#define TFT_DC   GPIO_NUM_21    // 
#define TFT_RST  GPIO_NUM_18    // Reset
#define TFT_BCKL GPIO_NUM_5     // Backlight

esp_err_t tft_init();





#endif // TFT_H