#pragma once

/// @defgroup led led
/// @ingroup libhw

#include "gpio.hpp"
#include <stdint.h>

enum class Color : uint8_t { RED, GREEN, YELLOW, BLUE, WHITE };

class LED {
    Pin pin;
    Color color;

   public:
    LED(Pin pin = 0, Color c = Color::GREEN);
};

extern LED led0;
