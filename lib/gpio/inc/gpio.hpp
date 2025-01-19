#pragma once

#include "object.hpp"
#include "os.hpp"

/// @defgroup gpio gpio
/// @ingroup libhw
/// @{

class Port : public Object {
    std::string name;

   public:
    Port(std::string name);
    virtual std::string tag();  ///< @return type/class tag
    virtual std::string val();  ///< @returns @rev value in string
    /// @name power/activity control
    /// @{
    virtual void on();   ///< switch on
    virtual void off();  ///< switch off
    /// @}
};

extern Port A;
extern Port B;
extern Port C;
extern Port D;

/// @brief pin index in @ref Port
typedef uint8_t PinIndex;

/// @brief @ref Pin i/o mode
enum class PinState { HIGH, LOW, INPUT };

/// @brief @ref gpio pin
class Pin : public Object {
    Port *port;
    PinIndex index;
    PinState state;

   public:
    Pin(Port *port, PinIndex index);
    virtual std::string tag();  ///< @return type/class tag
    virtual std::string val();  ///< @returns @rev value in string
    /// @name power/activity control
    /// @{
    virtual void on();   ///< switch on
    virtual void off();  ///< switch off
    /// @}
};

extern Pin B5;

/// @}
