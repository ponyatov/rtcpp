// #pragma once

// /// @defgroup type type
// /// @ingroup cli
// /// @{

// enum class Type { Int, Hex, Oct, Bin, Num, Ptr, Obj };

// #include "int.hpp"

// /// @brief universal typed data element (tagged union)
// struct Cell {
//     Type t;  ///< type/class tag
//     union {
//         int n;      ///< integer
//         float f;    ///< float
//         void* p;    ///< raw pointer
//         Object* o;  ///< @ref Object in heap
//     } v;            ///< value
// };

// /// @}
