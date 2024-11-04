#ifndef MOTOR_H
#define MOTOR_H

#include "zf_common_headfile.h"
#include "pid.h"

#define MOTOR_LEN TIM1_PWM_MAP3_CH1_E9
#define MOTOR_REN TIM1_PWM_MAP3_CH4_E14
#define MOTOR_LPH E11
#define MOTOR_RPH E13

#define MOTOR_DUTY_MAX 9000

#define MOTOR_DUTY_MIN 0

#define MOTOR_SPEED_MAX 18

extern int32_t left_motor_speed;
extern int32_t right_motor_speed;

extern int32_t left_motor_speed_now;
extern int32_t right_motor_speed_now;

extern uint32_t left_motor_duty;
extern uint32_t right_motor_duty;

extern pid left_motor_pid;
extern pid right_motor_pid;
// typedef enum
// {
//     MOTOR_FORWARD = 0,
//     MOTOR_BACKWARD,
// } motor_dir;

int motor_init(void);

void left_motor_set_speed(int32_t speed);

void right_motor_set_speed(int32_t speed);

void left_motor_set_duty(uint32_t duty);

void right_motor_set_duty(uint32_t duty);

void motor_get_speed(void);


void motor_run_it();



#endif
