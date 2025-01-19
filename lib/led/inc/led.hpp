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
    Pin *pin;     ///< assigned @ref GPIO pin
    Color color;  ///< @ref Color (fixed set)
    bool state;   ///< current state: on/off

   public:
    LED(Pin *pin, Color color = Color::GREEN);
    virtual std::string tag();  ///< @return type/class tag
    virtual std::string val();  ///< @returns @rev value in string
    /// @name power/activity control
    /// @{
    virtual void on();   ///< switch on
    virtual void off();  ///< switch off
    /// @}
};

extern LED led;

/// @}
