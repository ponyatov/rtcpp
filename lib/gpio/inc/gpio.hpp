#pragma once

#include <stdint.h>

/// @defgroup gpio gpio
/// @ingroup libhw

class Pin {
    uint16_t port;

   public:
    Pin(uint16_t port);
};
