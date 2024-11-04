#ifndef PID_H_
#define PID_H_
#include "stdint.h"

typedef struct
{
    float kp;
    float ki;
    float kd;
    float error;
    float error_last;
    float integral;
    float derivative;
    float output;
    float max_output;
    float min_output;
} pid;

void pid_init(pid *pid, float kp, float ki, float kd, float max_output, float min_output);

void pid_calc(pid *pid, float setpoint, float actual);

void pid_incremental_init(pid *pid, float kp, float ki, float kd, float max_output, float min_output);

void pid_incremental_calc(pid *pid, float setpoint, float actual);

#endif /* PID_H_ */


