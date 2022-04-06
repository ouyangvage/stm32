#ifndef _cao_motor_h_
#define _cao_motor_h_

#include "tim.h"

typedef struct 
{
  int16_t line;
  int16_t angular;
}Velocity;



extern void motor_left(int16_t pwm);
extern void motor_right(int16_t pwm);

extern void differential_device(Velocity velocity);
#endif
