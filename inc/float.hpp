#pragma once

#include "object.hpp"

/// @defgroup float float
/// @ingroup prim
/// @{

class Float : public Object {
    float value;

   public:
    Float(char *c);
    Float(float n);
};

/// @}
