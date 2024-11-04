#include "fast_compute.h"

 
/**
 * @brief 快速计算平方根
 * @param x 输入值
 * @return int 输出值
 * @note 该函数用于快速计算平方根
 */
uint32_t fast_sqrt(uint32_t x)
{
    uint32_t sqrt = 0;
    uint32_t shift = 15;
    uint32_t sqrt2; // 已确认部分的平方
    while (shift >= 0)
    {
        sqrt2 = ((sqrt << 1) + (1 << shift)) << shift;
        if (sqrt2 <= x)
        {
            sqrt += (1 << shift);
            x -= sqrt2;
        }
        shift--;
    }
    return sqrt;
}

/**
 * @brief 快速计算平方根
 * @param x 输入值
 * @return float 输出值
 * @note 该函数用于快速计算平方根
 */
float fast_sqrtf(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int *)&x;
    i = 0x5f3759df - (i >> 1);
    x = *(float *)&i;
    x = x * (1.5f - xhalf * x * x);
    return 1.0f / x;
}

/**
 * @brief 快速计算平方根
 * @param x 输入值
 * @return double 输出值
 */
double fast_sqrtl(double x)
{
    double xhalf = 0.5 * x;
    long long i = *(long long *)&x;
    i = 0x5fe6ec85e7de30da - (i >> 1);
    x = *(double *)&i;
    x = x * (1.5 - xhalf * x * x);
    return 1.0l / x;
}

float fast_expf(float x)
{
    float sum = 1.0;  // 0! = 1
    float term = 1.0; // 用于计算每一项
    for (int i = 1; i <= 20; ++i)
    {                  // 使用20项
        term *= x / i; // 计算 x^i / i!
        sum += term;
    }
    return sum;
}

/**
 * @brief 快速计算正切值
 * @param tan 输入值
 * @return float 输出值
 * @note 该函数用于快速计算正切值
 */
float fast_arctanf_1(float tan)
{
    float angle = (ABS(tan) > 1.0f) ? 
    90.0f - ABS(1.0f / tan) * (45.0f - (ABS(1.0f / tan) - 1.0f) * (14.0f + 3.83f * ABS(1.0f / tan))) : 
    ABS(tan) * (45.0f - (ABS(tan) - 1.0f) * (14.0f + 3.83f * ABS(tan)));

    return (tan > 0) ? angle : -angle;
}

/**
 * @brief 快速计算正切值
 * @param x 输入值
 * @param y 输入值
 * @return float 输出值
 * @note 该函数用于快速计算正切值
 */
float fast_arctan_2(float x, float y)
{
    float tan, angle;

    if (x == 0 && y == 0) // 不存在
        return 0;

    if (x == 0) // y轴上
    {
        if (y > 0)
            return 90;
        else
            return -90;
    }

    if (y == 0) // x轴上
    {
        if (x > 0)
            return 0;
        else
            return -180.0f;
    }

    tan = y / x;
    angle = fast_arctanf_1(tan);
    if (x < 0 && angle > 0)
        angle -= 180.0f;
    else if (x < 0 && angle < 0)
        angle += 180.0f;
    return angle;
}

/**
 * @brief 快速计算反正弦值
 * @param x 输入值
 * @return float 输出值
 * @note 该函数用于快速计算反正弦值
 */
float fast_arcsin(float x)
{
    return fast_arctanf_1(x / fast_sqrtf(1 - x * x));
}
