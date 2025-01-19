#include "vm.hpp"
#include <stdio.h>
#include <assert.h>
#include "type.hpp"
#include "int.hpp"
#include <sstream>

const char VM::tag[] = "vm";

VM::VM() : Object() { Dp = 0; }

std::string VM::val() {
    std::ostringstream os("[ ");
    os << ']';
    return os.str();
    // for (size_t i = 0; i < Dp; i++) {  //
    //     Cell c = D[i];
    //     switch (c.t) {
    //         case Type::Int:
    //             std::cerr << "int:" << c.v.n << ' ';
    //             break;
    //         case Type::Hex:
    //             std::cerr << "hex:" << c.v.n << ' ';
    //             break;
    //         case Type::Oct:
    //             std::cerr << "oct:" << c.v.n << ' ';
    //             break;
    //         case Type::Bin:
    //             std::cerr << "bin:" << c.v.n << ' ';
    //             break;
    //         case Type::Float:
    //             fprintf(stderr, "num:%f ", c.v.f);
    //             break;
    //         default:
    //             fprintf(stderr, "???:%i ", c.v.n);
    //     }
    // }
}

void VM::push(int n) {  //
    push({Type::Int, n});
}

void VM::push(Cell c) {
    D[Dp++] = c;
    assert(Dp < Dsz);
}

VM vm;
