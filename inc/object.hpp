#pragma once

/// @defgroup object object
/// @brief managed (ref-counted) resource/object
/// @ingroup cli
/// @{

#ifdef LINUX
#include <list>
#endif

/// @brief managed (ref-counted) resource/object
class Object {
    size_t ref;  ///< ref counter
#ifdef LINUX
    std::list<Object*> nest;  ///< optional nested elements
#endif
   public:
    Object();
    virtual ~Object();
};

/// @}
