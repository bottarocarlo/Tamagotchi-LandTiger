/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           funct_joystick.h
** Last modified Date:  2018-12-30
** Last Version:        V1.00
** Descriptions:        High level joystick management functions
** Correlated files:    lib_joystick.c, funct_joystick.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/


#include "GLCD/GLCD.h"
#include "tamagocy.h"
#include "timer/timer.h"
#include "RIT/RIT.h"


#define GIMP_IMAGE_WIDTH (20)
#define GIMP_IMAGE_HEIGHT (13)
#define GIMP_IMAGE_BYTES_PER_PIXEL (2) /* 2:RGB16, 3:RGB, 4:RGBA */
#define GIMP_IMAGE_PIXEL_DATA ((guint8*) GIMP_IMAGE_pixel_data)
static const uint8_t GIMP_IMAGE_pixel_data[20 * 13 * 2 + 1] =
("\377\377\377\377\377\377\337\377\376\377\377\367\337\377\377\367\376\377\377"
 "\377\377\377\376\377\337\377\377\377\377\377\377\377\377\377\377\377\377\377"
 "\377\377\377\377\376\377\376\377\337\367\377\377\376\377\377\377\376\377\276"
 "\377Y\377\367\366Z\377\377\367\377\367\337\377\377\377\377\377\377\377\377"
 "\377\377\377\377\377\376\377\377\377\377\377\377\377\335\377\337\377\325\376"
 "\013\345g\334J\375J\375\220\376\274\377\337\377\377\367\377\377\377\377\377"
 "\377\377\377\377\377\377\377\377\367\276\377\376\377\377\377\221\335\346\253"
 "\210\324\247\253\352\365\204\202h\314O\376\337\377\377\377\377\377\377\377"
 "\377\377\377\377\377\377\377\377\377\367\376\377\337\367\370\376\011\325\012"
 "\345\353\375\315\375\211\365\310\253*\355I\375\365\366\337\377\377\377\377"
 "\377\377\377\377\377\377\377\336\377\377\377\376\377\377\377\216\355\201z"
 ")\365\212\335\305\212\014\335\353\375k\355M\375\215\365\336\377\377\377\377"
 "\377\377\377\377\377\377\377\376\377\377\377\376\367\234\367\014\365\253\314"
 "\313\375I\355$z\210\304*\355\301a\207\274N\365[\377\377\377\377\377\377\377"
 "\377\377\377\377\377\377\377\377\377\377\377\377\217\375\312\375\250\243("
 "\314\255\375\214\375)\345\247\243\351\334n\355\337\377\377\377\377\377\377"
 "\377\377\377\337\377\377\377\337\377\337\377\376\377o\355\013\375F\264i\274"
 "\355\365\012\355\012\345+\376\013\365\324\375\376\367\377\377\377\377\377\377"
 "\377\377\376\377\377\367\377\367\377\377\377\367<\377+\324\213\375(\314l\355"
 "\311\243\203\202)\375\253\334\236\377\377\377\377\377\377\377\377\377\377"
 "\377\377\377\377\367\377\377\376\377\337\377\377\377\372\376\254\334\307\313"
 "&\324\251\354I\344\315\334:\367\377\377\336\377\377\377\377\377\377\377\377"
 "\377\377\377\377\377\377\377\336\377\337\377\377\377\377\367\377\377}\377"
 "\070\357U\356\271\376\377\377\377\367\337\377\377\377\377\377\377\377\377\377"
 "\377\377\377\377\377\377\377\367\377\367\337\377\376\377\376\377\277\377\337"
 "\377\376\377\337\367\377\377\335\377\375\377\377\377\377\367\377\377\377\377"
 "\377\377\377\377");
 
 
 /* GIMP RGBA C-Source image dump (kisspng-pizza-pixel-art-gif-image-tumblr-pixel-avatars-www-galleryhip-com-the-hipp-5b6d5d19cc86f8.5926239015338939138378(2).c) */

#define GIMP_IMAGE_WIDTH_1 (20)
#define GIMP_IMAGE_HEIGHT_1 (20)
#define GIMP_IMAGE_BYTES_PER_PIXEL_1 (2) /* 2:RGB16, 3:RGB, 4:RGBA */
#define GIMP_IMAGE_PIXEL_DATA_1 ((guint8*) GIMP_IMAGE_pixel_data)
static const uint8_t GIMP_IMAGE_pixel_data_1[20 * 20 * 2 + 1] =
("\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377'"
 "s\305j\362\224\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
 "\377\377\377\377\377\377\377\377\377\377\377\377\377\277\367x\326k\325\263"
 "\377\016\377\246\233\363\234\377\377\377\377\377\377\377\377\377\377\377\377"
 "\377\377\377\377\377\377\377\377\377\377\377\377}\357+\224P\377/\377\012\365"
 "\011\374j\364\352{\374\356\377\377\377\377\377\377\377\377\377\377\377\377"
 "\377\377\377\377\377\377<\347\222\275k\336\320\376'\375\012\374n\376\021\376"
 "\317\374\214\325\312\213\337\377\377\377\377\377\377\377\377\377\377\377\377"
 "\377\033\347i\203\357\376N\377\213\376\250\374\354\374\262\366\062\377\311\333"
 "\004\271\312\363\311\253\361{\377\377\377\377\377\377\377\377\377\377\064\245"
 "\307\304\362\376\255\376\250\364\207\352\353\363\265\377\362\367\310\333#"
 "\311&\302\305\301\010\333j\254\070\276\377\377\377\377\377\377\377\377(sP\377"
 "\256\376\250\373i\352\244\271\345\311\355\354\017\376\255\344)\272\003\251\245"
 "\271\316\374.\336Ls\377\377\377\377\377\377\377\377\357s\251\254\355\376h"
 "\375\306\312\245\271g\322o\366\062\377\363\376\022\377+\324\013\344\354\374v"
 "\377j\224\064\245\377\377\377\377\377\377\333\336(s\220\366\016\377\213\376"
 "\311\355\214\376\213\366H\343g\332\013\344\262\367\356\366m\376\216\375H\312"
 "\010r\233\326\377\377\377\377\377\377\332\336\344I*\224\013\275\357\376\315"
 "\376\350\365f\323\244\261\303\260\355\353r\377\361\367\314\334F\301\300\210"
 "\217{\337\367\377\377\377\377\377\377\337\377\316s+k\206b\313\274\257\376"
 "\017\377\352\375\246\333\247\323\263\377\264\377\315\375g\323G\322\344`x\316"
 "\377\377\377\377\377\377\377\377\377\377\377\377v\265+k\007k\346\253\352\364"
 "\012\366\252\376\013\377\252\364\347\311\347\332,\345K\315m\204\177\367\377"
 "\377\377\377\377\377\377\377\377\377\377\377\377\367\030\266\010:\205\253,\376"
 "\213\365*\366\251\345\307\313\203\261\006\312\215\376G\254\360\203\377\377\377"
 "\377\377\377\377\377\377\377\377\377\337\377\377\377\270\265\205{\316\254"
 "\250\253\212\375l\375J\376\013\376\313\375\353\356\321\377X\316\377\377\377"
 "\377\377\377\377\377\377\377\377\377\377\377\337\377\324\234K\224\257\244"
 "\353b'\254\214\376\247\243\252\243\012\305\016\377\257\377\377\377\377\377\377"
 "\377\377\377\377\377\377\377\377\377\377\377\377\377\323\244\252\234,\255"
 "\061t\254\243'\244\017|\020|\012c\205bP\234\377\377\377\377\377\377\377\377\377"
 "\377\377\377\377\377\377\377\377\377\237\367x\316<\347\377\377Q\234bR\063\245"
 "\377\377\337\377\236\367\337\377\377\377\377\377\377\377\377\377\377\377\377"
 "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377N\224H\224\232"
 "\326\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
 "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377x\326\320"
 "\305/\204\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
 "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
 "\377\010k\276\367\377\377\377\377\377\377\377\377\377\377");
 

uint16_t bar_lenght=82;
uint16_t bar_height=30;
extern int dead;
extern int meal;
extern int snack;
volatile uint16_t happines_x_pos,satiety_x_pos,bars_y_pos;

volatile uint16_t radius,xc,yc;

volatile int eating=0;	
volatile int hungry=0;
extern int flag;
volatile int lingua=0;
uint16_t happy_bar_start;
uint16_t happy_bar_end;
uint16_t satiety_bar_start;
uint16_t satiety_bar_end;



static void delay_ms(uint16_t ms)    
{ 
	uint16_t i,j; 
	for( i = 0; i < ms; i++ )
	{ 
		for( j = 0; j < 1141; j++ );
	}
}

void draw_snack(uint16_t xi,int yi,uint16_t color){
	
	int x,y,i,colorone,posX=20,posY=210;
	int w= GIMP_IMAGE_WIDTH;
	int h= GIMP_IMAGE_HEIGHT;
	uint16_t* Gimp_p = (uint16_t*)&(GIMP_IMAGE_pixel_data);
	x=y=0;
	
	for(i=0;i<w*h;i++){
		uint16_t Gimpy = *Gimp_p++;
		if(x==2*GIMP_IMAGE_WIDTH){
		y+=2;
		x=0;
		}
	colorone=Gimpy;
		LCD_SetPoint(posX+x,posY+y,colorone);
		LCD_SetPoint(posX+x,posY+y+1,colorone);
		LCD_SetPoint(posX+x+1,posY+y,colorone);
		LCD_SetPoint(posX+x+1,posY+y+1,colorone);
		x+=2;
	}
}

void draw_meal(uint16_t xi,int yi,uint16_t color){
	int x,y,i,colorone,posX=30,posY=210;
	int w= GIMP_IMAGE_WIDTH_1;
	int h= GIMP_IMAGE_HEIGHT_1;
	uint16_t* Gimp_p = (uint16_t*)&(GIMP_IMAGE_pixel_data_1);
	x=y=0;
	
	for(i=0;i<w*h;i++){
		uint16_t Gimpy = *Gimp_p++;
		if(x==2*GIMP_IMAGE_WIDTH_1){
		y+=2;
		x=0;
		}
	colorone=Gimpy;
		LCD_SetPoint(posX+x,posY+y,colorone);
		LCD_SetPoint(posX+x,posY+y+1,colorone);
		LCD_SetPoint(posX+x+1,posY+y,colorone);
		LCD_SetPoint(posX+x+1,posY+y+1,colorone);
		x+=2;
	}
}


void draw_food(uint16_t xi,int yi,uint16_t color){
	
	if(meal==1){
		draw_meal(xi,yi,color);
	}
	if(snack==1){
		draw_snack(xi,yi,color);
	}
}

void draw_animazione(){
	
	
	if(lingua==0){
		lingua=1;
		drawer_animation(xc,yc);
	}
	else{
		drawer(xc,yc);
		lingua=0;
		//LCD_DrawLine(xc,yc,160,210,Black);
	}
}


void eat(void){
	
	uint16_t i;
	uint16_t max_x=50;
	draw_food(0,0,Blue);
	for(i=1;i<max_x;i+=10){
		draw_tamagocy(xc-i,yc);
	}
	LCD_DrawRectangle(30,210,50,50,White);
	for(i=1;i<50;i+=15){
		draw_tamagocy(xc-max_x+i,yc);
	}
	draw_tamagocy(xc,yc);
	
}




void draw_tamagocy(uint16_t Xpos,uint16_t Ypos){
	
	drawer(Xpos,Ypos);
	
}




void draw_menu(){
	char a[200];
	
	bars_y_pos=41;
	happines_x_pos=20;
	satiety_x_pos=140;
	
	happy_bar_end=happines_x_pos-2+bar_lenght;
	happy_bar_start=happines_x_pos;
	satiety_bar_end=satiety_x_pos-2+bar_lenght;
	satiety_bar_start=satiety_x_pos;
	
	//coomands
	LCD_DrawRectangle_empty(0,270,120,50,Black);
	GUI_Text(15, 280, (uint8_t *) " MEAL  ", Black,White);
	LCD_DrawRectangle_empty(120,270,240,50,Black);
	GUI_Text(135, 280, (uint8_t *) " SNACK  ", Black,White);
	
	
	GUI_Text(happines_x_pos, 25, (uint8_t *) "Happiness  ", Black,White);
	LCD_DrawRectangle_empty(happines_x_pos-1,bars_y_pos-1,bar_lenght,bar_height,Black);
	add_green_bar_happy();
	add_green_bar_happy();
	add_green_bar_happy();
	add_green_bar_happy();
	
	GUI_Text(satiety_x_pos, 25, (uint8_t *) "Satiety  ", Black,White);
	LCD_DrawRectangle_empty(satiety_x_pos-1,bars_y_pos-1,bar_lenght,bar_height,Black);
	add_green_bar_satiety();
	add_green_bar_satiety();
	add_green_bar_satiety();
	add_green_bar_satiety();


		sprintf(a,"  Age: %02d:%02d:%02d",0,0,0);
		
		GUI_Text(60,0,(uint8_t *)a,Black,White);

}



void create_tamagochy(uint16_t Xpos,uint16_t Ypos, uint16_t r){
	
	volatile uint16_t xleft,yleft,xright,yright,xtop,ytop,xbotton,ybotton;
		
	xleft=Xpos-radius;
	xright=Xpos+radius;
	xtop=xbotton=Xpos;
	
	yleft=yright=Ypos;
	ytop=Ypos-radius;
	ybotton=Ypos+radius;
	
	xc=Xpos;
	yc=Ypos;
	radius=r;
	//body
	
	
	
	draw_tamagocy(xc,yc);

	//menu
	draw_menu();
	


}



void runaway_sequence(void){
	uint16_t i;
	char a[200];
	for(i=0;i<MAX_X+radius;i+=16){
		
		draw_tamagocy(xc+i,yc);
		
	}
	//LCD_DrawRectangle(0,40,240,320-40,White);
	
	LCD_Clear(White);
	
	
	LCD_DrawRectangle_empty(0,270,240,50,Red);
	GUI_Text(100, 280, (uint8_t *) " RESET  ", Black,White);
	
	sprintf(a,"  Age: %02d:%02d:%02d",0,0,0);
		
	GUI_Text(60,0,(uint8_t *)a,Black,White);
	
	GUI_Text(80,220 , (uint8_t *) "Oh f***k... ", Red,White);

	
}


void add_green_bar_happy(){
	
	uint16_t lenght=20;
	uint16_t height=28;
	
	
	if(happines_x_pos<happy_bar_end){
		LCD_DrawRectangle(happines_x_pos+1,bars_y_pos+1,lenght-2,height-2,Black);
		happines_x_pos+=lenght;
	}
	
	
}
void remove_green_bar_happy(){
	
	uint16_t lenght=20;
	uint16_t height=28;
 
	
	if(happines_x_pos>happy_bar_start){
		happines_x_pos-=lenght;
		LCD_DrawRectangle(happines_x_pos,bars_y_pos,lenght,height,White);
	}
	if(happines_x_pos==happy_bar_start){
		dead=1;
	}	
	
}

void add_green_bar_satiety(){
	
	uint16_t lenght=20;
	uint16_t height=28;
	
	
	
	if(satiety_x_pos<satiety_bar_end){
		LCD_DrawRectangle(satiety_x_pos+1,bars_y_pos+1,lenght-2,height-2,Black);
		satiety_x_pos+=lenght;
	}
	
	
}
void remove_green_bar_satiety(){
	
	uint16_t lenght=20;
	uint16_t height=28;
 
	
	if(satiety_x_pos>satiety_bar_start){
		satiety_x_pos-=lenght;
		LCD_DrawRectangle(satiety_x_pos,bars_y_pos,lenght,height,White);
		
	}
		
	if(satiety_x_pos==satiety_bar_start){
		dead=1;
	}
	

	
	
	
}


