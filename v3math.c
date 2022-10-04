//header files
#include "v3math.h"

//functions
void v3_from_points(float *dst, float *a, float *b)  { // form v3 from a to b
    dst[0] = abs(b[0] - a[0]);
    dst[1] = abs(b[1] - a[1]);
    dst[2] = abs(b[2] - a[2]);
}

void v3_add(float *dst, float *a, float *b) {
    dst[0] = a[0] + b[0];
    dst[1] = a[1] + b[1];
    dst[2] = a[2] + b[2];
}

void v3_subtract(float *dst, float *a, float *b){
    dst[0] = a[0] - b[0];
    dst[1] = a[1] - b[1];
    dst[2] = a[2] - b[2];
}

float v3_dot_product(float *a, float *b) {
    return (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]);
}

void v3_cross_product(float *dst, float *a, float *b) {
    //0 = x, 1 = y, 2 = z
    //         (ay * bz) - (az * by)
    //     C = (az * bx) - (ax * bz)
    //         (ax * by) - (ay * bx)
    dst[0] = (a[1] * b[2]) - (a[2] * b[1]);
    dst[1] = (a[2] * b[0]) - (a[0] * b[2]);
    dst[2] = (a[0] * b[1]) - (a[1] * b[0]);
}

void v3_scale(float *dst, float s) {
    dst[0] = dst[0] * s;
    dst[1] = dst[1] * s;
    dst[2] = dst[2] * s;
}

float v3_angle(float *a, float *b) { // angle between a and b
    return acosf(v3_dot_product(a,b) / (v3_length(a) * v3_length(b)));
}

float v3_angle_quick(float *a, float *b) {// angle between a and b; no cos-1
    return v3_dot_product(a,b) / (v3_length(a) * v3_length(b));
}

void v3_reflect(float *dst, float *v, float *n) {
dst[0] = 2 * v3_dot_product(v, n) * n[0] - v[0];
dst[1] = 2 * v3_dot_product(v, n) * n[1] - v[1];
dst[2] = 2 * v3_dot_product(v, n) * n[2] - v[2];
}

float v3_length(float *a) {
return sqrt(pow(a[0],2) + pow(a[1],2) + pow(a[2],2));
}

void v3_normalize(float *dst, float *a) {
    float length = v3_length(a);
    dst[0] = a[0] / length;
    dst[1] = a[1] / length;
    dst[2] = a[2] / length;
}
