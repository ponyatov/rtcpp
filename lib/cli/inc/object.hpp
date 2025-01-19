#pragma once

#include "os.hpp"

/// @defgroup object object
/// @ingroup type
/// @{

class Object {
    //    public:
    //     /// @name garbage collection
    //     /// @{
    //     size_t ref;  ///< ref.counter

    //     // Object* next;         ///< next object in @ref pool
    //     // static Object* pool;  ///< global @ref Object pool
    //     /// @}

   public:
    Object();
    ~Object();
    /// @name dump
    /// @{
    void dump(char divider = '\n');
    /// @}
    //     /// @name power/activity control
    //     /// @{
    //     virtual void on();   ///< enable
    //     virtual void off();  ///< disable
    //     /// @}
};
/// @}
