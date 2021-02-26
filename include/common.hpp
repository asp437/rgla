#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

namespace RGLA {
    typedef unsigned int uint;

    typedef unsigned char uint8;
    typedef signed char int8;
    typedef unsigned short uint16;
    typedef signed short int16;
    typedef unsigned int uint32;
    typedef signed int int32;
    typedef unsigned long long int uint64;
    typedef signed long long int int64;

    static_assert(sizeof(uint8) == 1, "uint8 size is not 1 byte");
    static_assert(sizeof(int8) == 1, "int8 size is not 1 byte");
    static_assert(sizeof(uint16) == 2, "uint16 size is not 2 byte");
    static_assert(sizeof(int16) == 2, "int16 size is not 2 byte");
    static_assert(sizeof(uint32) == 4, "uint32 size is not 4 byte");
    static_assert(sizeof(int32) == 4, "int32 size is not 4 byte");
    static_assert(sizeof(uint64) == 8, "uint64 size is not 8 byte");
    static_assert(sizeof(int64) == 8, "int64 size is not 8 byte");

#define RGLA_UNUSED(v) {(void)v;}
#define RGLA_ENSURE(v, text) {if (!(v)) { throw std::runtime_error("Ensure failed: "#text); } }
}
