/*
 * API_init.h
 *
 *  Created on: Apr 3, 2023
 *      Author: alan
 */

#ifndef API_INC_API_INIT_H_
#define API_INC_API_INIT_H_

#include <stdio.h>
#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */
#include <stdbool.h>

void Error_Handler(void);
void assert_failed(uint8_t *file, uint32_t line);
void SystemClock_Config(void);

#endif /* API_INC_API_INIT_H_ */
