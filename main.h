#ifndef __MAIN_H
#define __MAIN_H

/*	Kieu So Nguyen Co Dau	*/
typedef   signed           char int8_t;
typedef   signed 	       int int16_t;
typedef   signed long      int int32_t;

/*	Kieu So Nguyen Khong Dau */
typedef   unsigned         char uint8_t;
typedef   unsigned 	       int  uint16_t;
typedef   unsigned long    int  uint32_t;
/*	Kieu So Thuc */
typedef   float            float32_t;

#include <AT89X52.H>
#include <stdio.h>
#include <string.h>

#include "User/delay/delay.h"
#include "User/lcd1602/lcd1602.h"
#include "User/uart/uart.h"
#define LED_DON	P1	
#define DQ	P3_7

#define BT1	P3_2
#define BT2	P3_3
#define BT3	P3_4
#define BT4	P3_5

#endif