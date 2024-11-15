/*
 * tm1637.c
 *
 *  Created on: May 19, 2022
 *      Author: lth
 */

#include "main.h"
#include "tm1638.h"

#ifdef DEBUG
#include <stdio.h>
#endif

void tm1638_cs_on(Tm1638_HandleTypeDef *tm1638) {
    HAL_GPIO_WritePin(tm1638->cs_port, tm1638->cs_pin, GPIO_PIN_RESET); // Pull low for CS to be "on"
}

void tm1638_cs_off(Tm1638_HandleTypeDef *tm1638) {
    HAL_GPIO_WritePin(tm1638->cs_port, tm1638->cs_pin, GPIO_PIN_SET); // Pull high for CS to be "off"
}

Tm1638_result_t tm1638_init(Tm1638_HandleTypeDef *tm1638, SPI_HandleTypeDef *spi, GPIO_TypeDef *cs_port, uint16_t cs_pin) {

    Tm1638_result_t result = Tm1638_Ok;

    TM1638_DBG("Initializing TM1638");

    tm1638->spi = spi;
    tm1638->cs_port = cs_port;
    tm1638->cs_pin = cs_pin;

    tm1638_cs_off(tm1638);

    tm1638->is_initialized = TM1638_TRUE;

    uint8_t data = TM1638_DISPLAY_COMMAND | TM1638_DISPLAY_ON | 1;
    tm1638_cs_on(tm1638);
    HAL_SPI_Transmit(tm1638->spi, &data, 1, HAL_MAX_DELAY);
    tm1638_cs_off(tm1638);

    HAL_Delay(1);

    data = TM1638_DATA_COMMAND | TM1638_TEST;
    tm1638_cs_on(tm1638);
    HAL_SPI_Transmit(tm1638->spi, &data, 1, HAL_MAX_DELAY);
    tm1638_cs_off(tm1638);

    return result;

}

/*
 * vim: ts=4 et nowrap autoindent
 */
