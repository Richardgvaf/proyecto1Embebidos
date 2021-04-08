#ifndef _LIBRASP_H_
#define _LIBRASP_H_
#define GPIO_BASE   0x20200000
#define GPFSEL0 	0x20200000
#define GPFSEL1 	0x20200004
#define GPFSEL2 	0x20200008
#define GPFSEL3 	0x2020000C
#define GPFSEL4 	0x20200010
#define GPFSEL5 	0x20200014

#define GPSET0 		0x2020001C
#define GPSET1		0X20200020

#define CLEARSET0   0X20200028
#define CLEARSET1   0X2020002C
	void pinMode (int pin,int MODE);
	void digitalWrite(int pin,int value);
	int digitalRead(int pin);

#endif