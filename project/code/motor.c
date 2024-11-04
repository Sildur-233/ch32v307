#include "motor.h"

int32_t left_motor_speed = 0;
int32_t right_motor_speed = 0;

int32_t left_motor_speed_now = 0;
int32_t right_motor_speed_now = 0;

uint32_t left_motor_duty = 0;
uint32_t right_motor_duty = 0;

pid left_motor_pid;
pid right_motor_pid;

/**
 * @brief 初始化电机
 * 
 */
int motor_init(void)
{
    // 初始化PWM

    /**
     * todo: duty置零
     */
    left_motor_duty = 0;
    right_motor_duty = 0;

    pwm_init(MOTOR_LEN, 10000, left_motor_duty);
    pwm_init(MOTOR_REN, 10000, right_motor_duty);
    // 初始化PH引脚
    gpio_init(MOTOR_LPH, GPO, 0, GPO_PUSH_PULL);
    gpio_init(MOTOR_RPH, GPO, 0, GPO_PUSH_PULL);
    // 初始化编码器
    encoder_quad_init(TIM4_ENCOEDER, TIM4_ENCOEDER_MAP1_CH1_D12, TIM4_ENCOEDER_MAP1_CH2_D13);
    encoder_quad_init(TIM5_ENCOEDER, TIM5_ENCOEDER_MAP0_CH1_A0, TIM5_ENCOEDER_MAP0_CH2_A1);
    // 初始化PID
    pid_init(&left_motor_pid, 800, 30, 175, MOTOR_DUTY_MAX, MOTOR_DUTY_MIN);
    pid_init(&right_motor_pid, 800, 30, 175, MOTOR_DUTY_MAX, MOTOR_DUTY_MIN);

    return 0;
}

/**
 * @brief 设置左电机速度
 * @param speed 速度
 */
void left_motor_set_speed(int32_t speed)
{
    left_motor_speed = speed;
}

/**
 * @brief 设置右电机速度
 * @param speed 速度
 */
void right_motor_set_speed(int32_t speed)
{
    right_motor_speed = speed;
}

/**
 * @brief 设置左电机占空比
 * @param duty 占空比
 */
void left_motor_set_duty(uint32_t duty)
{
    left_motor_duty = duty;
    pwm_set_duty(MOTOR_LEN, duty);
}

/**
 * @brief 设置右电机占空比
 * @param duty 占空比
 */
void right_motor_set_duty(uint32_t duty)
{
    right_motor_duty = duty;
    pwm_set_duty(MOTOR_REN, duty);
}

/**
 * @brief 获取电机速度
 */
void motor_get_speed(void)
{
    left_motor_speed_now = -encoder_get_count(TIM4_ENCOEDER);
    encoder_clear_count(TIM4_ENCOEDER);
    right_motor_speed_now = encoder_get_count(TIM5_ENCOEDER);
    encoder_clear_count(TIM5_ENCOEDER);
}

/**
 * @brief 运行电机
 */
void motor_run_it(void)
{
    motor_get_speed();
    pid_calc(&left_motor_pid, left_motor_speed, left_motor_speed_now);
    pid_calc(&right_motor_pid, right_motor_speed, right_motor_speed_now);
    left_motor_set_duty(left_motor_pid.output);
    right_motor_set_duty(right_motor_pid.output);
}
