#pragma once

/// @defgroup type type
/// @ingroup cli
/// @{

enum class Type { Int, Hex, Oct, Bin, Float, Ptr };

#include "int.hpp"

/// @brief universal typed data element (tagged union)
struct Cell {
    Type t;  ///< type/class tag
    union {
        int n;    ///< integer
        float f;  ///< float
        void* p;  ///< raw pointer
    } v;          ///< value
};

/// @}
