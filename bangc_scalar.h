#pragma once

#include <bang.h>
#include <stdint.h>

__nram__ int64_t scalar_i64_buffer[1];
__nram__ float scalar_f_buffer[1];

__mlu_func__ float load_float(float *ptr) {
    return __load_gdram(ptr);
}

__mlu_func__ void store_float(float *ptr, float value) {
    __store_gdram(ptr, value);
}

__mlu_func__ int64_t load_int64(int64_t *ptr) {
    __memcpy(scalar_i64_buffer, ptr, sizeof(int64_t), GDRAM2NRAM);
    return scalar_i64_buffer[0];
}

__mlu_func__ void store_int64(int64_t *ptr, int64_t value) {
    scalar_i64_buffer[0] = value;
    __memcpy(ptr, scalar_i64_buffer, sizeof(int64_t), NRAM2GDRAM);
}

__mlu_func__ float scalar_exp(float value) {
    scalar_f_buffer[0] = value;
    __bang_mul_scalar(scalar_f_buffer, scalar_f_buffer, 1.4426950408889634f, 1);
    __bang_pow2(scalar_f_buffer, scalar_f_buffer, 1);
    return scalar_f_buffer[0];
}

__mlu_func__ float scalar_log(float value) {
    scalar_f_buffer[0] = value;
    __bang_log2(scalar_f_buffer, scalar_f_buffer, 1);
    __bang_mul_scalar(scalar_f_buffer, scalar_f_buffer, 0.6931471805599453f, 1);
    return scalar_f_buffer[0];
}

__mlu_func__ float scalar_sqrt(float value) {
    scalar_f_buffer[0] = value;
    __bang_sqrt(scalar_f_buffer, scalar_f_buffer, 1);
    return scalar_f_buffer[0];
}

__mlu_func__ float scalar_sigmoid(float value) {
    return 1.0f / (1.0f + scalar_exp(-value));
}

__mlu_func__ float scalar_tanh(float value) {
    return 2.0f / (1.0f + scalar_exp(-2.0f * value)) - 1.0f;
}
