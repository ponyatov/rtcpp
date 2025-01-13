#pragma once

#include <string>

/// @defgroup object object
/// @brief managed (ref-counted) resource/object
/// @ingroup cli
/// @{

#ifdef LINUX
#include <list>
#endif

/// @brief managed (ref-counted) resource/object
class Object {
    size_t ref;           ///< ref counter
    static Object *pool;  ///< global objects list
    Object *next;         ///< next object in @ref pool
#ifdef LINUX
    std::list<Object *> nest;  ///< optional nested elements
#endif
   public:
    /// @name constructor
    /// @{
    Object();
    virtual ~Object();
    /// @}
    /// @name dump/stringify
    /// @{
    virtual void dump();  ///< dump object
    /// @}
};

/// @}
