/*
 * tm1637.c
 *
 *  Created on: May 19, 2022
 *      Author: lth
 */


#include "main.h"
#include "tm1637.h"

Tm1637_result_t tm1637_init(Tm1627_HandleTypeDef *tm1637, TIM_HandleTypeDef *timer) {
	Tm1637_result_t result = Tm1637_Ok;
	tm1637->timer = timer;
	tm1637->is_initialized = 1;
	return result;
}

void tm1637_tick(Tm1627_HandleTypeDef *tm1637) {
	if (tm1637 && tm1637->is_initialized) {

		tm1637->tick_count += 1;

		switch (tm1637->state) {
		case TM1637_STATE_IDLE:
			break;
		default:
			Error_Handler();
		}

	}
}
