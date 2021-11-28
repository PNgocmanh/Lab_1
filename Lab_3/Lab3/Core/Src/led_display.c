/*
 * led_display.c
 *
 *  Created on: Nov 8, 2021
 *      Author: Ngoc Manh
 */

# include "main.h"
# include "led_display.h"
int street1_arr [3] = {5 ,2 ,3};
int street2_arr [3] = {5 ,2 ,3};
int arr2 [3] = {0 ,0 ,0}; // temp arr


void display7SEG ( int num , GPIO_TypeDef * GPIO1 , uint16_t GPIO_PIN0 ,uint16_t GPIO_PIN1 , uint16_t GPIO_PIN2 , uint16_t GPIO_PIN3 , uint16_t GPIO_PIN4 , uint16_t GPIO_PIN5 , uint16_t GPIO_PIN6 )
{
    switch ( num ){
    case 0:
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN0 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN1 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN2 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN3 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN4 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN5 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN6 , SET );
        break ;
    case 1:
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN0 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN1 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN2 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN3 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN4 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN5 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN6 , SET );
        break ;
    case 2:
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN0 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN1 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN2 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN3 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN4 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN5 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN6 , RESET );
        break ;
    case 3:
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN0 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN1 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN2 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN3 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN4 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN5 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN6 , RESET );
        break ;
    case 4:
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN0 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN1 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN2 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN3 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN4 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN5 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN6 , RESET );
        break ;
    case 5:
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN0 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN1 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN2 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN3 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN4 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN5 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN6 , RESET );
        break ;
    case 6:
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN0 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN1 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN2 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN3 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN4 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN5 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN6 , RESET );
        break ;
    case 7:
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN0 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN1 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN2 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN3 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN4 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN5 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN6 , SET );
        break ;
    case 8:
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN0 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN1 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN2 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN3 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN4 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN5 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN6 , RESET );
        break ;
    case 9:
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN0 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN1 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN2 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN3 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN4 , SET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN5 , RESET );
        HAL_GPIO_WritePin (GPIO1 , GPIO_PIN6 , RESET );
        break ;
    }
}

void traffic_light ( uint16_t GPIO_Pin1 , uint16_t GPIO_Pin2 , uint16_t GPIO_Pin3 , int count , int arr []){
    switch ( count ){
    case 0:
        HAL_GPIO_WritePin (GPIOB , GPIO_Pin1 , RESET );
        HAL_GPIO_WritePin (GPIOB , GPIO_Pin2 , SET);
        HAL_GPIO_WritePin (GPIOB , GPIO_Pin3 , SET);
        break ;
    case 1:
        HAL_GPIO_WritePin (GPIOB , GPIO_Pin1 , SET);
        HAL_GPIO_WritePin (GPIOB , GPIO_Pin2 , SET);
        HAL_GPIO_WritePin (GPIOB , GPIO_Pin3 , RESET );
        break ;
    case 2:
        HAL_GPIO_WritePin (GPIOB , GPIO_Pin1 , SET);
        HAL_GPIO_WritePin (GPIOB , GPIO_Pin2 , RESET );
        HAL_GPIO_WritePin (GPIOB , GPIO_Pin3 , SET);
        break ;
    }
    arr [ count ]--;
}
void traffic_light_4 (int count_vled , int count_hled ){
//////////////////////////// HORIZONTAL LEDS ////////////////////////////
    traffic_light ( GPIO_PIN_7 , GPIO_PIN_8 , GPIO_PIN_9 , count_hled , street2_arr );

    ///////////////////////// VERTICAL LEDS ///////////////////////
    traffic_light ( GPIO_PIN_10 , GPIO_PIN_11 , GPIO_PIN_12 , count_vled , street1_arr );
}

////////////////////// MODE 1/////////////////////////////////////
int count_vled = 0;
int count_hled = 2;
void mode_1 (){
    if( count_vled >= 3) count_vled = 0;
    if( count_hled < 0) count_hled = 2;
        traffic_light_4 ( count_vled , count_hled );
        display7SEG ( street1_arr [ count_vled ], GPIOB , GPIO_PIN_1 , GPIO_PIN_2 , GPIO_PIN_3 , GPIO_PIN_4 , GPIO_PIN_5 , GPIO_PIN_6, GPIO_PIN_7 );
        display7SEG ( street2_arr [ count_hled ], GPIOA ,GPIO_PIN_7 , GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10 , GPIO_PIN_11 , GPIO_PIN_12 , GPIO_PIN_13 );
        display7SEG ( street2_arr [ count_hled ], GPIOB , GPIO_PIN_8 , GPIO_PIN_9 , GPIO_PIN_10 , GPIO_PIN_11 , GPIO_PIN_12 , GPIO_PIN_13 , GPIO_PIN_14 );
    if( street1_arr [ count_vled ] <= 1){
        street1_arr [ count_vled ] = arr2 [ count_vled ];
        count_vled ++;
    }
    if( street2_arr [ count_hled ] <= 1){
        street2_arr [ count_hled ] = arr2 [ count_hled ];
        count_hled --;
    }
}

//////////////////////// MODE 2 //////////////////////////////
int counter_mode2 = 1;
void mode_2 (){
    if( counter_mode2 == 1){
        HAL_GPIO_WritePin (GPIOA , GPIO_PIN_3 | GPIO_PIN_6 , RESET);
        counter_mode2 = 2;
    }
    else {
        HAL_GPIO_WritePin (GPIOA, GPIO_PIN_3 | GPIO_PIN_6 , SET );
        counter_mode2 = 1;
    }
    HAL_GPIO_WritePin (GPIOA , GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_4 | GPIO_PIN_5 , SET );
    display7SEG (2, GPIOB , GPIO_PIN_1 , GPIO_PIN_2 , GPIO_PIN_3 , GPIO_PIN_4 , GPIO_PIN_5 , GPIO_PIN_6, GPIO_PIN_7 );
}

// //////////// MODE 3///////////////////
int counter_mode3 = 1;
void mode_3 (){
    if( counter_mode3 == 1){
        HAL_GPIO_WritePin (GPIOA , GPIO_PIN_2 | GPIO_PIN_5 , RESET);
        counter_mode3 = 2;
    }
    else {
        HAL_GPIO_WritePin (GPIOA , GPIO_PIN_2 | GPIO_PIN_5 , SET );
        counter_mode3 = 1;
    }
    HAL_GPIO_WritePin (GPIOA , GPIO_PIN_1 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_6 , SET );
    display7SEG (3, GPIOB , GPIO_PIN_1 , GPIO_PIN_2 , GPIO_PIN_3 , GPIO_PIN_4 , GPIO_PIN_5 , GPIO_PIN_6, GPIO_PIN_7 );
}

// ///////////// MODE 4////////////////
int counter_mode4 = 1;
void mode_4 (){
    if( counter_mode4 == 1){
        HAL_GPIO_WritePin (GPIOA , GPIO_PIN_1 | GPIO_PIN_4 , RESET);
        counter_mode4 = 2;
    }
    else {
        HAL_GPIO_WritePin (GPIOA , GPIO_PIN_1 | GPIO_PIN_4 , SET );
        counter_mode4 = 1;
    }
    HAL_GPIO_WritePin (GPIOA , GPIO_PIN_7 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_12 , SET );
    display7SEG (4, GPIOB , GPIO_PIN_1 , GPIO_PIN_2 , GPIO_PIN_3 , GPIO_PIN_4 , GPIO_PIN_5 , GPIO_PIN_6 , GPIO_PIN_7);
}


