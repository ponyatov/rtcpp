#include "object.hpp"

/// @defgroup vm vm
/// @ingroup cli
/// @{

/// @brief @ref VM command
class Cmd : public Object {};

/// @brief Virtual Machine
class VM : public Object {
    /// @name data stack
    /// @{
    static const size_t Dsz = 0x10;  ///< size
    int D[Dsz];                      ///< data stack
    size_t Dp;                       ///< data stack pointer

    /// @}
   public:
    VM() { Dp = 0; }
    void dump();
    /// @name data stack
    /// @{
    void push(int n);  ///< `( -- n)` add integer to top of stack
    /// @}
};

extern VM vm;
/// @}
