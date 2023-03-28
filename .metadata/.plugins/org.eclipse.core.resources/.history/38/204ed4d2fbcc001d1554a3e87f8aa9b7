/*
 * API_delay.c
 *
 *  Created on: Mar 18, 2023
 *      Author: alan
 */
/* Implementation of non-blocking delay functions */
#include "API_delay.h"

void delayInit(delay_t * delay, tick_t duration) {
	// After setting the delay duration, the delay running is set to false

	delay->duration = duration;
	delay->running = false;
}

bool_t delayRead(delay_t * delay) {
	//Using a non blocking delay, the function returns false, but if its false, it gets the tick and
	//changes the delay running to true, so it can switch up between states

	if(delay->running == false){
		delay->startTime = HAL_GetTick();
		delay->running = true;
	} else if(delay->running == true) {
		if(HAL_GetTick() - delay->startTime >= delay->duration) {
			delay->running = false;
			return true;
		}
	}
	return false;
}
void delayWrite(delay_t * delay, tick_t duration) {
	// changes the duration for the delay


	delay->duration = duration;
}


