#pragma once

#include "object.hpp"
#include "type.hpp"
#include <iostream>

/// @defgroup vm vm
/// @ingroup cli
/// @{

/// @brief @ref VM command
class Cmd : public Object {};

/// @brief Virtual Machine
class VM : public Object {
    static const char tag[];
    /// @name data stack
    /// @{
    static const size_t Dsz = 0x10;  ///< @brief size
    Cell D[Dsz];                     ///< @brief data stack
    size_t Dp;                       ///< @brief data stack pointer

    /// @}
   public:
    VM();  ///< @brief construct & initialize
    // void dump(char divider = '\n');  ///< @brief print state: @ref D
    std::string val();  ///< @ref D dump
    /// @name data stack
    /// @{
    void push(int n);   ///< `( -- n)` add integer to top of stack
    void push(Cell c);  ///< `( -- o)`
    /// @}
};

extern VM vm;  ///< single global @ref cli @ref VM
/// @}
