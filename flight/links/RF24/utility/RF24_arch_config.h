
#ifndef __ARCH_CONFIG_H__
#define __ARCH_CONFIG_H__

  #define RF24_LINUX
  
  #include <stdint.h>
  #include <stdio.h>
  #include <time.h>
  #include <string.h>
  #include <sys/time.h>
  #include <stddef.h>
  
//   #include "bcm2835.h"
//   #include "spi.h"
  #define _SPI spi
	
  #if defined SPI_HAS_TRANSACTION && !defined SPI_UART && !defined SOFTSPI
    #define RF24_SPI_TRANSACTIONS
  #endif	
  // GCC a Arduino Missing
  #define _BV(x) (1<<(x))
  #define pgm_read_word(p) (*(p))
  #define pgm_read_byte(p) (*(p))
  
  //typedef uint16_t prog_uint16_t;
  #define PSTR(x) (x)
  #define printf_P printf
  #define strlen_P strlen
  #define PROGMEM
  #define PRIPSTR "%s"

  #ifdef SERIAL_DEBUG
	#define IF_SERIAL_DEBUG(x) ({x;})
  #else
	#define IF_SERIAL_DEBUG(x)
  #endif
  
  #define digitalWrite(pin, value) GPIO::Write(pin, value)
  #define pinMode(pin,value) GPIO::setMode(pin,value);
  #define OUTPUT GPIO::Output
  
#endif