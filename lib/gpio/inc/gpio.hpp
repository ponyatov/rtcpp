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
};

extern Port A;
extern Port B;
extern Port C;
extern Port D;

/// @brief pin index in @ref Port
typedef uint8_t PinIndex;

/// @brief @ref gpio pin
class Pin : public Object {
    Port *port;
    PinIndex index;

   public:
    Pin(Port *port, PinIndex index);
    virtual std::string tag();  ///< @return type/class tag
    virtual std::string val();  ///< @returns @rev value in string
};

extern Pin B5;

/// @}
