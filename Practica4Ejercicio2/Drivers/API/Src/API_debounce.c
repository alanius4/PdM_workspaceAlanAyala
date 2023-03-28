/*
 * API_debounce.c
 *
 *  Created on: Mar 27, 2023
 *      Author: alan
 */

/* Includes ------------------------------------------------------------------*/
#include "API_debounce.h"

/* Private functions ---------------------------------------------------------*/
/* ################ Button state definitions ################ */
/* This typedef can not be declared as static or private variable because it is on a .c file*/

typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RISING,
} debounceState_t;

static delay_t delay;
static debounceState_t actualState;
static bool_t isPressed;


bool_t readKey(){
	bool_t flag = false;
	if (isPressed) {
		flag = true;
		isPressed = false;
	}

	return flag;
}


void debounceFSM_init(){
	/* pone el estado inicial a BUTTON UP*/
	actualState = BUTTON_UP;
	delayInit(&delay, DEBOUNCE_TIME);
}


void debounceFSM_update(){
	switch(actualState){
	/* checkea si el boton fue apretado , y despues del delay pasa al estado falling*/
	case BUTTON_UP:
		if(BSP_PB_GetState(BUTTON_USER)){
			/* Update to next state */
			actualState = BUTTON_FALLING;
			/* Start the delay count */
			delayRead(&delay);
		}
		break;

	case BUTTON_FALLING:

		if(delayRead(&delay)){
			/* If after de-bouncing time the button is still pressed, it is assumed
			 * that the user has pressed the button */
			if(BSP_PB_GetState(BUTTON_USER)) {

				actualState = BUTTON_DOWN;

				isPressed = true;
			}
			else{
				/* en caso de ruido volver al estado anterior*/
				actualState = BUTTON_UP;
			}
		}
		break;

	case BUTTON_DOWN:
		if(!BSP_PB_GetState(BUTTON_USER)){
			actualState = BUTTON_RISING;
			delayRead(&delay);
		}
		break;

	case BUTTON_RISING:
		/* checkea si el boton fue soltado, en caso de que siga apretado vuelve al
		 * estado anterior, de lo contrario pasa al estado UP*/
		if(delayRead(&delay)){
			if(!BSP_PB_GetState(BUTTON_USER)){
				actualState = BUTTON_UP;
				isPressed = false;
			}
			else{
				/* en caso de ruido volver al estado anterior*/
				actualState = BUTTON_DOWN;
			}
		}
		break;
	default:
		actualState = BUTTON_UP;
		break;
	}

}
