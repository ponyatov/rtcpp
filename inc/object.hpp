#pragma once

/// @defgroup object object
/// @brief managed (ref-counted) resource/object
/// @ingroup cli
/// @{

#include <list>

/// @brief managed (ref-counted) resource/object
class Object {
    size_t ref;               ///< ref counter
    std::list<Object*> nest;  ///< optional nested elements
   public:
    Object();
    virtual ~Object();
};

/// @}
