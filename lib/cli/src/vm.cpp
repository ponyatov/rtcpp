#include "vm.hpp"
#include "os.hpp"

VM::VM() { Dp = 0; }

void VM::dump(char divider) {
    std::cerr << "vm: [ ";
    for (uint8_t i = 0; i < Dp; i++) std::cerr << D[i] << ' ';
    std::cerr << "]" << divider;
}

void VM::push(int n) {
    D[Dp++] = n;
    assert(Dp < Dsz);
}

int VM::pop() {
    assert(Dp > 0);
    return D[--Dp];
}

VM vm;
