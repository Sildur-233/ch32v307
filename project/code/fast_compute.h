#ifndef FAST_COMPUTE_H
#define FAST_COMPUTE_H
#include "stdint.h"

#define ANGLE_MAX 180.0f
#define ANGLE_MIN -180.0f
#define PI (3.14159265f)

#define LIMIT(x, min, max)                  ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))
#define ABS(x)                              ((x) > 0 ? (x) : -(x))
#define DIV(Number, Prescaler, Threshold)   ((Prescaler == 0.0f) ? Threshold : (Number / Prescaler))
#define Power2(x)                           (x * x)
#define MAX_2(x, y)                         ((x >= y) ? x : y)
#define MAX_3(x, y, z)                      ((z >= MAX_2(x, y)) ? z : MAX_2(x, y))

uint32_t fast_sqrt(uint32_t x);

float fast_sqrtf(float x);

double fast_sqrtl(double x);

float fast_expf(float x);

float fast_arctanf_1(float tan);

float fast_arctan_2(float x, float y);

float fast_arcsin(float x);

#endif
