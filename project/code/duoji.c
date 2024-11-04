#include "duoji.h"

/**
 * @brief 计算占空比
 * @param angle 角度
 * @return int 占空比
 */
int duty_compute(float angle)
{
    float ret = 5.555555f * angle + 250.0f;
    return (int)ret;
}

/**
 * @brief 舵机初始化
 * @param angle 初始角度
 * @note 该函数用于初始化舵机
 */
void duoji_init(float angle)
{
    pwm_init(TIM8_PWM_MAP0_CH1_C6, 50, duty_compute(angle));
}

/**
 * @brief 设置舵机角度
 * @param angle 角度
 * @note 该函数用于设置舵机角度
 */
void duoji_set_angle(float angle)
{
    pwm_set_duty(TIM8_PWM_MAP0_CH1_C6, duty_compute(angle));
}
