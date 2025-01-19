#include "object.hpp"
#include "os.hpp"

#pragma once

/// @defgroup gpio gpio
/// @ingroup libhw
/// @{

class Port : public Object {
    char name;

   public:
    Port(char name);
    void dump(char divider = '\n');
};

extern Port A;
extern Port B;
extern Port C;
extern Port D;

/// @brief pin index in @ref Port
typedef uint8_t PinIndex;

/// @brief @ref Pin i/o mode
enum class PinState : uint8_t { HIGH, LOW, INPUT };

/// @brief @ref gpio pin
class Pin : public Object {
    Port *port;
    PinIndex index;
    PinState state;

   public:
    Pin(Port *port, PinIndex index, PinState state = PinState::INPUT);
    void dump(char divider = '\n');
    /// @name power/activity control
    /// @{
    void on();   ///< switch on
    void off();  ///< switch off

    /// @}
};

extern Pin B5;

/// @}
