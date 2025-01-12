#pragma once

#include <cstdint>

/// @defgroup gpio gpio
/// @ingroup hal
/// @brief GPIO: raw pin access & configuration
/// @{

/// @brief @ref Pin logic (CMOS) state
enum class State : bool {
    HIGH = true,  ///< logical `1`
    LOW = false   ///< logicad `0`
};

/// @brief MCU port
class Port {};

/// @brief @ref Pin index in port
// using Index = uint8_t;
struct Index {
    uint8_t i : 4;  ///< `0..15` limited to 4 bit
};

/// @brief MCU/GPIO digital pin
class Pin {
    State state;  ///< current/cached @ref State
    Port port;    ///< MCU port
    Index index;  ///< pin index in @ref port

   public:
    Pin(Port p, State state);
    State get();
    void set(State s);
};

/// @}
