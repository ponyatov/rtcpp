#pragma once

/// @defgroup led led
/// @ingroup libhw
/// @{

#include "gpio.hpp"
#include <stdint.h>

enum class Color : uint8_t { RED, GREEN, YELLOW, BLUE, WHITE };

/// @brief LED: Light Emission Diode
class LED {
    Pin *pin;     ///< assigned @ref GPIO pin
    Color color;  ///< @ref Color (fixed set)
    bool state;   ///< current state: on/off

   public:
    LED(Pin *pin, Color color = Color::GREEN);
    void dump();  ///< print led info & it's @ref state
    void on();    ///< switch on
    void off();   ///< switch off
};

extern LED led;

/// @}
