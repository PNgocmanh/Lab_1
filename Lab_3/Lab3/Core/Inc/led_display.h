/*
 * led_display.h
 *
 *  Created on: Nov 8, 2021
 *      Author: Ngoc Manh
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

int street1_arr [3];
int street2_arr [3];
int arr2 [3];
void display7SEG ( int num , GPIO_TypeDef * GPIO1 , uint16_t GPIO_PIN0 , uint16_t GPIO_PIN1 , uint16_t GPIO_PIN2 , uint16_t GPIO_PIN3 , uint16_t GPIO_PIN4 , uint16_t GPIO_PIN5 , uint16_t GPIO_PIN6 );
void traffic_light ( uint16_t GPIO_Pin1 , uint16_t GPIO_Pin2 ,uint16_t GPIO_Pin3 , int count , int arr []);
void traffic_light_4 (int count_vled , int count_hled );
void mode_1 ();
void mode_2 ();
void mode_3 ();
void mode_4 ();

#endif /* INC_LED_DISPLAY_H_ */
