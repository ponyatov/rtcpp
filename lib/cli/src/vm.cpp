#include "vm.hpp"
#include <stdio.h>
#include <assert.h>
#include "type.hpp"
#include "int.hpp"

VM::VM() : Object() { Dp = 0; }

void VM::dump() {
    fprintf(stderr, "\n[ ");
    for (size_t i = 0; i < Dp; i++) {  //
        Cell c = D[i];
        switch (c.t) {
            case Type::Int:
                fprintf(stderr, "int:%i ", c.v.n);
                break;
            case Type::Hex:
                fprintf(stderr, "hex:%x ", c.v.n);
                break;
            case Type::Oct:
                fprintf(stderr, "oct:%o ", c.v.n);
                break;
            case Type::Bin:
                fprintf(stderr, "bin:%i ", c.v.n);
                break;
            case Type::Float:
                fprintf(stderr, "num:%f ", c.v.f);
                break;
            default:
                fprintf(stderr, "???:%i ", c.v.n);
        }
    }
    fprintf(stderr, "]\n");
}

void VM::push(int n) {  //
    push({Type::Int, n});
}

void VM::push(Cell c) {
    D[Dp++] = c;
    assert(Dp < Dsz);
}

VM vm;
