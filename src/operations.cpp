#include "../include/operations.hpp"

int32_t add(int32_t a, int32_t b) {
    if (a > 0 && b > 0 && a > INT32_MAX - b) {
        return INT32_MAX;
    }
    else if (a < 0 && b < 0 && a < INT32_MIN - b) {
        return INT32_MIN;
    }
    
    return a + b;
}

int32_t sub(int32_t a, int32_t b) {
    return add(a, b * -1);
}

int32_t mul(int32_t a, int32_t b) {
    if (a == INT32_MIN && b == -1 || b == INT32_MIN && a == -1) {
        return INT32_MAX;
    }

    if (a > 0) {
        if (b > 0 && a > INT32_MAX / b) return INT32_MAX;
        else if (b < 0 && b < INT32_MIN / a) return INT32_MIN;
    
    }
    else if (a < 0) {
        if (b > 0 && a < INT32_MIN / b) return INT32_MIN;
        else if (b < 0 && b > INT32_MAX / a) return INT32_MAX;
    }

    return a * b;
}

int32_t del(int32_t a, int32_t b) {
    if (b == 0) { 
        printf("Incorrect operation: division by zero");
        exit(1);
    }
    if (a == INT32_MIN && b == -1) return INT32_MAX;

    return a / b;
}

int32_t pow(int32_t a, int32_t b) {
    if (b <= 0) return 1;
    int32_t result = a;

    for (int32_t i = 0; i < b - 1; ++i) {
        result = mul(result, a);
        if (result == INT32_MAX) return INT32_MAX;
        else if (result == INT32_MIN) return INT32_MIN;
    }

    return result;
}

int32_t fact(int32_t a) {
    if (a <= 1) return 1;
    int32_t result = mul(a, fact(a - 1));

    return result;
}