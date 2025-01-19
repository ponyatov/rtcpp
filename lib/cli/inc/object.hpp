#pragma once

#include <stdint.h>
#include <stdlib.h>

/// @defgroup object object
/// @ingroup type
/// @{

class Object {
    size_t ref;           ///< ref.counter
    Object* next;         ///< next object in @ref pool
    static Object* pool;  ///< global @ref Object pool
   public:
    Object();
    virtual ~Object();
};
/// @}
