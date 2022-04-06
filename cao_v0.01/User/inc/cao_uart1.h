#ifndef _cao_uart1_h_
#define _cao_uart1_h_

#include "usart.h"
extern uint8_t rx_buff[255];
extern uint8_t tx_buff[255];

extern void read_command(void);
#endif
