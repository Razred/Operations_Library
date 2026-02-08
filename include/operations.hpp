#pragma once

#include <cstdint>
#include <cstdio>
#include <stdlib.h>

namespace operations {

enum class OperationalStatus : uint8_t {
    AllRight = 0,
    ParseError,
    ValidationError,
    UnsupportedOperation,
    DivisionByZero,
    Overflow
};


bool add(int64_t a, int64_t b, int64_t &result, OperationalStatus &status);

bool sub(int64_t a, int64_t b, int64_t &result, OperationalStatus &status);

bool mul(int64_t a, int64_t b, int64_t &result, OperationalStatus &status);

bool div(int64_t a, int64_t b, int64_t &result, OperationalStatus &status);

bool pow(int64_t a, int64_t b, int64_t &result, OperationalStatus &status);

bool fact(uint64_t a, uint64_t &result, OperationalStatus &status);

}









