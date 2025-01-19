#include "os.hpp"
#include "gpio.hpp"
#include <iostream>

#pragma once

/// @defgroup led led
/// @ingroup libhw
/// @{

enum class Color : uint8_t { RED, GREEN, YELLOW, BLUE, WHITE };

/// @brief LED: Light Emission Diode
class LED : public Object {
    static const char tag[];  ///< type/class tag
    Pin *pin;                 ///< assigned @ref GPIO pin
    Color color;              ///< @ref Color (fixed set)
    bool state;               ///< current state: on/off

   public:
    LED(Pin *pin, Color color = Color::GREEN);
    void dump(char divider = '\n');
    void on();   ///< switch on
    void off();  ///< switch off
};

extern LED led;

/// @}
