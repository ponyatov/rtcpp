#pragma once

/// @defgroup led led
/// @ingroup libhw

#include "gpio.hpp"

class LED {
    Pin pin;

   public:
    LED(Pin pin);
};
