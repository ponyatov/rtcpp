#pragma once

#include "os.hpp"

/// @defgroup object object
/// @ingroup type
/// @{

class Object {
    public:
    /// @name garbage collection
    /// @{
    size_t ref;  ///< ref.counter

    // Object* next;         ///< next object in @ref pool
    // static Object* pool;  ///< global @ref Object pool
    /// @}

   public:
    Object();
    virtual ~Object();
    virtual std::string tag();  ///< @return type/class tag
    virtual std::string val();  ///< @returns @rev value in string
    virtual void dump(char divider = '\n');
};
/// @}
