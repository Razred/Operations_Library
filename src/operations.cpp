#include "../include/operations.hpp"

#include <limits.h>

namespace operations {

namespace {

inline bool setAllRight(OperationalStatus &status) {
    status = OperationalStatus::AllRight;
    return true;
}

inline bool setError(OperationalStatus &status, OperationalStatus code) {
    status = code;
    return false;
}

}  //namespace

bool add(int64_t a, int64_t b, int64_t &result, OperationalStatus &status) {
    if ((b > 0 && a > INT64_MAX - b) || (b < 0 && a < INT64_MIN - b)) return setError(status, OperationalStatus::Overflow);

    result = a + b;
    return setAllRight(status);
}

bool sub(int64_t a, int64_t b, int64_t &result, OperationalStatus &status) {
    if ((b < 0 && a > INT64_MAX + b) || (b > 0 && a < INT64_MIN + b)) return setError(status, OperationalStatus::Overflow);

    result = a - b;
    return setAllRight(status);
}

bool mul(int64_t a, int64_t b, int64_t &result, OperationalStatus &status) {
    if (a == 0 || b == 0) {
        result = 0;
        return setAllRight(status);
    }

    if (a == -1 && b == INT64_MIN) return setError(status, OperationalStatus::Overflow);
    if (b == -1 && a == INT64_MIN) return setError(status, OperationalStatus::Overflow);
    
    int64_t tmp = a * b;
    if (tmp / b != a) return setError(status, OperationalStatus::Overflow);
    
    result = tmp;
    return setAllRight(status);
}

bool div(int64_t a, int64_t b, int64_t &result, OperationalStatus &status) {
    if (b == 0) return setError(status, OperationalStatus::DivisionByZero);

    if (a == INT64_MIN && b == -1) return setError(status, OperationalStatus::Overflow);

    result = a / b;
    return setAllRight(status);
}

bool pow(int64_t a, int64_t b, int64_t &result, OperationalStatus &status) {
    if (b < 0) return setError(status, OperationalStatus::ValidationError);

    int64_t res = 1;
    for (int64_t i = 0; i < b; ++i) {
        int64_t tmp = 0;
        if (!mul(res, a, tmp, status)) return false;  //mul уже ставит Overflow
        res = tmp;
    }

    result = res;
    return setAllRight(status);
}

bool fact(uint64_t a, uint64_t &result, OperationalStatus &status) {
    if (a <= 1) {
        result = 1;
        return setAllRight(status);
    }

    uint64_t prev = 0;
    if (!fact(a - 1, prev, status)) return false;

    if (prev > UINT64_MAX / a) return setError(status, OperationalStatus::Overflow);
    result = prev * a;
    return setAllRight(status);
}

}  //namespace operations