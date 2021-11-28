/*
 * input_reading.c
 *
 *  Created on: Nov 8, 2021
 *      Author: Ngoc Manh
 */

#include "main.h"
#include "input_reading.h"
#include "led_display.h"
GPIO_PinState buttonBuffer [ N0_OF_BUTTONS ];
// we define two buffers for
GPIO_PinState debounceButtonBuffer1 [ N0_OF_BUTTONS ];
GPIO_PinState debounceButtonBuffer2 [ N0_OF_BUTTONS ];

uint16_t pinButton [ N0_OF_BUTTONS ];

// we define a flag for a button pressed more than 1 second
static uint8_t flagForButtonPress1s [ N0_OF_BUTTONS ];
// we define counter for automatically increasing the value
// after the button is pressed more than 1 second .
static uint16_t counterForButtonPress1s [ N0_OF_BUTTONS ];

void getButton ( void ){
    pinButton [0] = GPIO_PIN_0 ;
    pinButton [1] = GPIO_PIN_14 ;
    pinButton [2] = GPIO_PIN_15 ;
    for (int i = 0 ; i < N0_OF_BUTTONS ; i++) {
        debounceButtonBuffer1 [i] = BUTTON_IS_RELEASED ;
        debounceButtonBuffer2 [i]= BUTTON_IS_RELEASED ;
        buttonBuffer [i]= BUTTON_IS_RELEASED ;
    }
}

void button_reading ( void ){
    for ( char i = 0; i < N0_OF_BUTTONS ; i ++){
        debounceButtonBuffer2 [i] = debounceButtonBuffer1 [i];
        debounceButtonBuffer1 [i] = HAL_GPIO_ReadPin (GPIOA ,
        pinButton [i]);
        if( debounceButtonBuffer1 [i] == debounceButtonBuffer2 [i])
            buttonBuffer [i] = debounceButtonBuffer1 [i];
            if( buttonBuffer [i] == BUTTON_IS_PRESSED ){
                // if a button is pressed , we start counting
                if( counterForButtonPress1s [i] < DURATION_FOR_AUTO_INCREASING ){
                    counterForButtonPress1s [i ]++;
                } else {
                // the flag is turned on when 1 second has passed
                // since the button is pressed .
                flagForButtonPress1s [i] = 1;
                // todo
                }
            } else {
                counterForButtonPress1s [i] = 0;
                flagForButtonPress1s [i] = 0;
            }
    }
}

unsigned char is_button_pressed ( uint8_t index ){
    if( index >= N0_OF_BUTTONS ) return 0;
    return ( buttonBuffer [ index ] == BUTTON_IS_PRESSED );
}
unsigned char is_button_pressed_1s ( unsigned char index ){
    if( index >= N0_OF_BUTTONS ) return 0xff;
    return ( flagForButtonPress1s [ index ] == 1);
}
