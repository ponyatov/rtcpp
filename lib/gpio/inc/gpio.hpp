#pragma once

/// @defgroup gpio gpio
/// @ingroup libhw
/// @{

#include <stdint.h>

class Port {
    char name;

   public:
    Port(char name);
};

extern Port A;
extern Port B;
extern Port C;
extern Port D;

/// @brief pin index in @ref Port
typedef uint8_t PinIndex;

/// @brief @ref gpio pin
class Pin {
    Port *port;
    PinIndex pin;

   public:
    Pin(Port *port, PinIndex pin);
};

extern Pin B5;

/// @}
