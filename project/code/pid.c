#include "pid.h"

/**
 * @brief PID初始化
 * @param pid PID结构体
 * @param kp 比例系数
 * @param ki 积分系数
 * @param kd 微分系数
 * @param max_output 最大输出
 * @param min_output 最小输出
 * @note 该函数用于初始化PID
 */
void pid_init(pid *pid, float kp, float ki, float kd, float max_output, float min_output)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->max_output = max_output;
    pid->min_output = min_output;
    pid->error = 0;
    pid->error_last = 0;
    pid->integral = 0;
    pid->derivative = 0;
    pid->output = 0;
}

/**
 * @brief PID计算
 * @param pid PID结构体
 * @param setpoint 期望值
 * @param actual 实际值
 * @note 该函数用于计算PID
 */
void pid_calc(pid *pid, float setpoint, float actual)
{
    pid->error = setpoint - actual;
    pid->integral += pid->error;
    pid->derivative = pid->error - pid->error_last;
    pid->output = pid->kp * pid->error + pid->ki * pid->integral + pid->kd * pid->derivative;
    pid->error_last = pid->error;
    if (pid->output > pid->max_output)
    {
        pid->output = pid->max_output;
    }
    else if (pid->output < pid->min_output)
    {
        pid->output = pid->min_output;
    }
}

/**
 * @brief 增量式PID初始化
 * @param pid PID结构体
 * @param kp 比例系数
 * @param ki 积分系数
 * @param kd 微分系数
 * @param max_output 最大输出
 * @param min_output 最小输出
 * @note 该函数用于初始化增量式PID
 */
void pid_incremental_init(pid *pid, float kp, float ki, float kd, float max_output, float min_output){
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->max_output = max_output;
    pid->min_output = min_output;
    pid->error = 0;
    pid->error_last = 0;
    pid->integral = 0;
    pid->derivative = 0;
    pid->output = 0;
}

/**
 * @brief 增量式PID计算
 * @param pid PID结构体
 * @param setpoint 期望值
 * @param actual 实际值
 * @note 该函数用于计算增量式PID
 */
void pid_incremental_calc(pid *pid, float setpoint, float actual){
    pid->error = setpoint - actual;
    pid->output = pid->kp * (pid->error - pid->error_last) + pid->ki * pid->error + pid->kd * (pid->error - 2 * pid->error_last + pid->derivative);
    pid->error_last = pid->error;
    pid->derivative = pid->error;
    if (pid->output > pid->max_output)
    {
        pid->output = pid->max_output;
    }
    else if (pid->output < pid->min_output)
    {
        pid->output = pid->min_output;
    }
}
