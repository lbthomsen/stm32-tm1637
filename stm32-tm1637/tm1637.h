/*
 * tm1637.h
 *
 *  Created on: May 19, 2022
 *      Author: lth
 */

#ifndef TM1637_H_
#define TM1637_H_

#define TM1637_STATE_IDLE 0

typedef struct {
	uint8_t is_initialized;
	TIM_HandleTypeDef *timer;
	uint32_t tick_count;
	uint8_t state;
} Tm1627_HandleTypeDef;

typedef enum {
	Tm1637_Ok,
	Tm1637_Err
} Tm1637_result_t;

Tm1637_result_t tm1637_init(Tm1627_HandleTypeDef *tm1637, TIM_HandleTypeDef *timer);
void tm1637_tick(Tm1627_HandleTypeDef *tm1637);

#endif /* TM1637_H_ */
