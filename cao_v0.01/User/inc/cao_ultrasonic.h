#ifndef _cao_ultrasionic_h_
#define _cao_ultrasionic_h_

#include "tim.h"

typedef struct{
	uint8_t start;
	uint8_t finish;
	uint32_t count;
	uint32_t period;
}Capture;

extern uint8_t capture_channel;
extern void capture_init(void);
extern uint32_t ultrasonic_measure(void);
#endif
