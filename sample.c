/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               main.c
** Descriptions:            The GLCD application function
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-11-7
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             Paolo Bernardi
** Modified date:           03/01/2020
** Version:                 v2.0
** Descriptions:            basic program for LCD and Touch Panel teaching
**
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/

#include <stdio.h>
#include "LPC17xx.h"
#include "GLCD/GLCD.h"
#include "./tamagocy.h"
#include "timer/timer.h"
#include "TouchPanel/TouchPanel.h"
#include "adc/adc.h"

#include "joystick/joystick.h"
#include "RIT/RIT.h"

#define SIMULATOR 1

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

volatile int meal=0;
volatile int snack=0;
volatile int dead=0;
volatile int time=0;
extern int hours,minutes,seconds;
extern int select,left,right;
extern int cuddles;

void 	action_selected(void);
void update_time(void);
void update_status_bar(void);
int main(void)
{
  SystemInit();  												/* System Initialization (i.e., PLL)  */
	joystick_init();											/* Joystick Initialization            */
  LCD_Initialization();
	//XMAX=240  YMAX=320
	TP_Init();
	TouchPanel_Calibrate();
	ADC_init();	
	LCD_Clear(White);

	create_tamagochy(120,160,80);
	
	init_RIT(0x004C4B40);									/* RIT Initialization 50 msec       */
	
	enable_RIT();												/* enable RIT to count 50ms				 */
	
	
	
	init_timer(0, 0, 0, 3,0x017D7840);   //1 secondo
	enable_timer(0);
	init_timer(2, 0, 0, 3, 0x1312D0); // 50 ms
	enable_timer(2);
	

  while (1)	
  {
		
		if(time && dead==0){
			NVIC_DisableIRQ(TIMER0_IRQn);
			NVIC_DisableIRQ(RIT_IRQn);
			time=0;
			update_time();
			//linguaccia
			draw_animazione();
			
			update_status_bar();
			if(dead){
				left=right=0;
				runaway_sequence();
				NVIC_EnableIRQ(RIT_IRQn);
				continue;
			}
			
			NVIC_EnableIRQ(TIMER0_IRQn);
			NVIC_EnableIRQ(RIT_IRQn);
		}
		
		if(select){
			NVIC_DisableIRQ(RIT_IRQn);
			NVIC_DisableIRQ(TIMER0_IRQn);
			select=0;
			action_selected();
			NVIC_EnableIRQ(RIT_IRQn);
			NVIC_EnableIRQ(TIMER0_IRQn);
		}
		if(left && dead==0){
			NVIC_DisableIRQ(TIMER0_IRQn);
			NVIC_DisableIRQ(RIT_IRQn);
			right=0;
			LCD_DrawRectangle_empty(120,270,240,50,Black);
			LCD_DrawRectangle_empty(0,270,120,50,Red);
			NVIC_EnableIRQ(RIT_IRQn);
			NVIC_EnableIRQ(TIMER0_IRQn);
		}
		if(right && dead==0){
			NVIC_DisableIRQ(TIMER0_IRQn);
			NVIC_DisableIRQ(RIT_IRQn);
			left=0;
			LCD_DrawRectangle_empty(0,270,120,50,Black);
			LCD_DrawRectangle_empty(120,270,240,50,Red);
			NVIC_EnableIRQ(RIT_IRQn);
			NVIC_EnableIRQ(TIMER0_IRQn);
		}
		if(cuddles == 1 || cuddles == 2){
			LCD_DrawCircle(70, 170, 3, Red);
			LCD_DrawCircle(115, 215, 3, Red);
			LCD_DrawCircle(80, 150, 3, Red);
			LCD_DrawCircle(30, 200, 3, Red);
			LCD_DrawCircle(200, 130, 3, Red);
			LCD_DrawCircle(170, 150, 3, Red);
			//GUI_Text(100, 110, (uint8_t *) "Cuddles",Black, White);
		}
		if(cuddles == 3){
			//GUI_Text(100, 110, (uint8_t *) "                    ",Black, White);
			LCD_DrawCircle(70, 170, 3, White);
			LCD_DrawCircle(115, 215, 3, White);
			LCD_DrawCircle(80, 150, 3, White);
			LCD_DrawCircle(30, 200, 3, White);
			LCD_DrawCircle(200, 130, 3, White);
			LCD_DrawCircle(170, 150, 3, White);
			add_green_bar_happy();
			cuddles = 0;
		}
		
  }
}



void update_time(void){
	char a[200];
	
		sprintf(a,"  Age: %02d:%02d:%02d",hours,minutes,seconds);
		
		GUI_Text(60,0,(uint8_t *)a,Black,White);
}
void update_status_bar(){
		if(seconds%5==0){
			remove_green_bar_happy();
			remove_green_bar_satiety();
		}
}

void 	action_selected(){
	
	if(dead){
				dead=0;
					left=right=0;
					seconds=minutes=hours=0;
					LCD_DrawRectangle_empty(0,270,240,50,Green);
					LCD_Clear(White);
					create_tamagochy(120,160,90);
					
				}
	if(left){
					left=0;
		
					LCD_DrawRectangle_empty(0,270,120,50,Green);
					LCD_DrawRectangle_empty(0,270,120,50,Black);
					meal=1;
					
					eat();
					meal=0;
					add_green_bar_satiety();
				
				
					
				}
		if(right){
					right=0;
					LCD_DrawRectangle_empty(120,270,240,50,Green);
					LCD_DrawRectangle_empty(120,270,240,50,Black);	
					snack=1;
					eat();
					snack=0;
					add_green_bar_happy();
				
				}
				
	
	
}
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
