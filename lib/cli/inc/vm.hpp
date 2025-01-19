#pragma once

#include "object.hpp"
// #include "type.hpp"
#include "os.hpp"

/// @defgroup vm vm
/// @ingroup cli
/// @{

/// @brief @ref VM command
class Cmd : public Object {};

/// @brief Virtual Machine
class VM : public Object {
    /// @name data stack
    /// @{
    static const uint8_t Dsz = 0x10;  ///< @brief size
    int D[Dsz];                       ///< @brief data stack
    size_t Dp;                        ///< @brief data stack pointer
                                      /// @}
   public:
    VM();                            ///< @brief construct & initialize
    void dump(char divider = '\n');  ///< dump @ref D
    /// @name data stack
    /// @{
    void push(int n);  ///< `( -- n)` add integer to top of stack
    int pop();         ///< `( n -- )` pop top element

    /// @}
};

extern VM vm;  ///< single global @ref cli @ref VM
/// @}
