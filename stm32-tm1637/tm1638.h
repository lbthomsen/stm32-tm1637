/*
 * tm1638.h
 *
 *  Created on: May 19, 2022
 *      Author: lth
 */

#ifndef TM1638_H_
#define TM1638_H_

#ifdef DEBUG
#define TM1638_DBG(...)    printf(__VA_ARGS__);\
                    printf("\n");
#else
#define TM1638_DBG(...)
#endif

#define TM1638_DATA_COMMAND    0b01000000
#define TM1638_DISPLAY_COMMAND 0b10000000
#define TM1638_ADDRESS_COMMAND 0b11000000

#define TM1638_DATA_WRITE      0b00000000
#define TM1638_DATA_READ       0b00000010
#define TM1638_ADDRESS_AUTO    0b00000000
#define TM1638_ADDRESS_FIXED   0b00000100
#define TM1638_TEST            0b00001000

#define TM1638_DISPLAY_OFF     0b00000000
#define TM1638_DISPLAY_ON      0b00001000
#define TM1638_INTENSITY_1     0b00000000
#define TM1638_INTENSITY_1     0b00000001
#define TM1638_INTENSITY_1     0b00000010
#define TM1638_INTENSITY_1     0b00000011
#define TM1638_INTENSITY_1     0b00000100
#define TM1638_INTENSITY_1     0b00000101
#define TM1638_INTENSITY_1     0b00000110
#define TM1638_INTENSITY_1     0b00000111

#define TM1638_FALSE 0;
#define TM1638_TRUE 1;

typedef struct {
    SPI_HandleTypeDef *spi;
    GPIO_TypeDef *cs_port;
    uint16_t cs_pin;
    uint8_t is_initialized;
} Tm1638_HandleTypeDef;

typedef enum {
    Tm1638_Ok,
    Tm1638_Err
} Tm1638_result_t;

Tm1638_result_t tm1638_init(Tm1638_HandleTypeDef *tm1638, SPI_HandleTypeDef *spi, GPIO_TypeDef *cs_port, uint16_t cs_pin);

#endif /* TM1638_H_ */
