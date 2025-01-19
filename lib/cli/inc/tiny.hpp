#pragma once

#include "object.hpp"

/// @brief tiny string
class tiny : public Object {
    uint8_t length;                   ///< current length
    static const uint8_t max = 0x10;  ///< max @ref tiny length
    char *value;                      ///< ASCII chars

   public:
    tiny(char *s);                     ///< allocate
    ~tiny();                           ///< free
    void dump(char dilimiter = '\n');  ///<
};
