/*
 * input_processing.c
 *
 *  Created on: Nov 8, 2021
 *      Author: Ngoc Manh
 */


# include "main.h"
# include "input_processing.h"
# include "input_reading.h"
# include "led_display.h"

enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED ,BUTTON_PRESSED_MORE_THAN_1_SECOND } ;
enum ButtonState buttonState [3] = { BUTTON_RELEASED ,BUTTON_RELEASED , BUTTON_RELEASED };
int time_duration = 0;
int mode = 0;
void increase_mode (){
    if( mode > 4 ) mode = 1;
    else mode ++;
}

void reset_mode (){
    // reset time_duration after transform to a mode and reset timer each when we didn ’t complete time ’s run cycle at mode 1
    for ( int i = 0; i < 3 ; i++){
        street2_arr [i] = arr2 [i];
        street1_arr [i] = arr2 [i];
    }
    time_duration = 0;
}
void fsm_for_input_processing ( void ){
    for ( int i = 0 ; i < N0_OF_BUTTONS ; i ++) {
        switch ( buttonState [i] ){
            case BUTTON_RELEASED :
                if( is_button_pressed (i)){
                    buttonState [i] = BUTTON_PRESSED ;
                    // INCREASE VALUE OF PORT A BY ONE UNIT
                    if(i == 0){ // first button .
                        increase_mode ();
                        if( mode > 1) reset_mode ();
                    }
                }
                break ;
            case BUTTON_PRESSED :
                if (! is_button_pressed (i)){
                    buttonState [i] = BUTTON_RELEASED ;
                } else {
                    if( is_button_pressed_1s (i) )
                        buttonState [i] = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
                }
                break ;
            case BUTTON_PRESSED_MORE_THAN_1_SECOND :
                if (! is_button_pressed (i)){
                    buttonState [i] = BUTTON_RELEASED ;
                }
                // todo
                break ;
        }
    }
}
