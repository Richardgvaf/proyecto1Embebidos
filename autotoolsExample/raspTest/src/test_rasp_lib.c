// ’Hello World!’ program#
#include <stdio.h>
#include <librasp.h>
#include <sys/mman.h>
#include <fcntl.h>

int main()
{
        int fd ;

        fd = open ("/dev/mem", O_RDWR | O_SYNC) ;

        //map a page of memory to gpio at offset 0x20200000 which is where GPIO goodnessstarts
        //gpio = (uint32_t *)mmap(0, getpagesize(), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0x20200000);



        //set gpio17 as an output
        pinMode (17, 1);

        //toggle gpio17 every second
        while(1){
                //set the pin high
                digitalWrite(17, 1);

                //sleep
                sleep(1);

                //set the pin to low
                digitalWrite(17, 0);

                sleep(1);
        }
}