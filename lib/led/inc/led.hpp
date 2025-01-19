#include "os.hpp"
#include "gpio.hpp"
// #include <iostream>

#pragma once

/// @defgroup led led
/// @ingroup libhw
/// @{

enum class Color : uint8_t { RED, GREEN, YELLOW, BLUE, WHITE };

enum class LEDState : bool { ON = true, OFF = false };

/// @brief LED: Light Emission Diode
class LED : public Object {
    Pin *pin;        ///< assigned @ref GPIO pin
    Color color;     ///< @ref Color (fixed set)
    LEDState state;  ///< current state: on/off

   public:
    LED(Pin *pin, Color color = Color::GREEN, LEDState state = LEDState::OFF);
    void dump(char divider = '\n');
    /// @name power/activity control
    /// @{
    void on();   ///< switch on
    void off();  ///< switch off
    /// @}
};

extern LED led;

/// @}
