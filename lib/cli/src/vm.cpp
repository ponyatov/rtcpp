#include "vm.hpp"
#include <stdio.h>
#include <assert.h>

void VM::dump() {
    fprintf(stderr, "\n[ ");
    for (int i = 0; i < Dp; i++) {  //
        fprintf(stderr, "%i ", D[i]);
    }
    fprintf(stderr, "]\n");
}

void VM::push(int n) {
    D[Dp++] = n;
    assert(Dp < Dsz);
}

VM vm;
