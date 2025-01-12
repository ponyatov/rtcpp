#pragma once

#include <stdint.h>

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
class Port {
    char name;

   public:
    Port(char name);
};

/// @brief 8-bit @ref Port
class Port8 : public Port {
   public:
    Port8(char name) : Port(name) {}
};

/// @brief 16-bit @ref Port
class Port16 : public Port {
   public:
    Port16(char name) : Port(name) {}
};

/// @brief @ref Pin index in port
// using Index = uint8_t;
union Index {
    uint8_t m7 : 3;   ///< `0..7` limited to 3 bit (max 7)
    uint8_t m15 : 4;  ///< `0..15` limited to 4 bit (max 15)
};

/// @brief MCU/GPIO digital pin
class Pin {
    State state;  ///< current/cached @ref State
    Port port;    ///< MCU port
    Index index;  ///< pin index in @ref port

   public:
    Pin(Port p, Index idx, State state);
    State get();
    void set(State s);
};

/// @}
