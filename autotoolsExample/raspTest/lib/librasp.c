#include <librasp.h>
#include <sys/mman.h>
#include <fcntl.h>
void pinMode (int pin,int MODE){
	int fd ;
	__uint32_t *gpio;
	//fd = open ("/dev/mem", O_RDWR | O_SYNC) ;
	if(pin < 10){
		gpio = GPFSEL0;
		
	}
	if(10 < pin < 20){
		gpio = GPFSEL1;
	}
	if(20 < pin < 30){
		gpio = GPFSEL2;
	}
	if(30 < pin < 40){
		gpio = GPFSEL3;
	}
	if(40 < pin < 50){
		gpio = GPFSEL4;
	}
	pin = pin % 10;
	if(MODE == 1){			//definimos mode == 1 como si fuera una salida
		*(gpio) = (*(gpio) & ~(7 << (pin*3)) | (1 << (pin*3)));
	}
	if(MODE == 0){			//definimos mode == 0 como si fuera una entrada
		*(gpio) = *(gpio) & ~(7 << (pin*3));
	}
	
}
void digitalWrite(int pin,int value){
	__uint32_t *gpio;
	if (value == 1){
		if(pin < 32){
			gpio = GPSET0;
		}
		else{
			gpio = GPSET1;
		}
		
	}
	if (value == 0){
		if(pin < 32){
			gpio = CLEARSET0;
		}
		else{
			gpio = CLEARSET1;
		}
	}
	pin = pin % 32;
	*(gpio + 10) = 1 << 17;
	*(gpio) = (*(gpio)  | (1 << pin));
}
int digitalRead(int pin){
	return 1;
}