/*
 * timer.h
 *
 *  Created on: Nov 8, 2021
 *      Author: Ngoc Manh
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#define TIMER_INTERUPT 10 // 10 miliseconds

#define TIMER_1s 1000 // 1000 miliseconds = 1 seconds
static int count_1s = TIMER_1s / TIMER_INTERUPT ;

#define TIMER_blinking 500 // 500 miliseconds = 0.5 seconds
static int count_500ms = TIMER_blinking / TIMER_INTERUPT ;

#endif /* INC_TIMER_H_ */
