#pragma once

/// @defgroup gpio gpio
/// @ingroup hal
/// @brief GPIO: raw pin access & configuration
/// @{

class Pin {
    bool state;

   public:
    bool get();
    void set(bool hilow);
};

/// @}
