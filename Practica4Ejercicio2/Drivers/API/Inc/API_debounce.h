/*
 * API_debounce.h
 *
 *  Created on: Mar 27, 2023
 *      Author: alan
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_



/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __API_DEBOUNCE_H
#define __API_DEBOUNCE_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */
#include <stdint.h>					/* <- Standard integer library */
#include <stdbool.h>				/* <- Standard boolean library*/
#include "API_delay.h"

/* Exported types ------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define DEBOUNCE_TIME 40
/* Exported functions ------------------------------------------------------- */
/* ################ My function definitions ################ */
bool_t readKey();
void debounceFSM_init();
void debounceFSM_update();


#endif /* __API_DEBOUNCE_H */

#endif /* API_INC_API_DEBOUNCE_H_ */
