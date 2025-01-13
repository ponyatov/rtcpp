#pragma once

#include "object.hpp"

/// @defgroup prim primitive
/// @ingroup object

/// @defgroup int int
/// @ingroup prim
/// @{
class Int : public Object {
    int value;

   public:
    Int(char *c);
    Int(int n);
};

/// @brief hexadecimal number
class Hex : public Int {
   public:
    Hex(char *c);
};

/// @brief octal number (file access constants)
class Oct : public Int {
   public:
    Oct(char *c);
};

/// @brief binary number
class Bin : public Int {
   public:
    Bin(char *c);
};

/// @}
