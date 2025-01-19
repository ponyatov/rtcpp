#include "vm.hpp"
#include "os.hpp"

VM::VM() { Dp = 0; }

std::string VM::tag() { return "vm"; }
std::string VM::val() {
    std::ostringstream os;
    os << " [ ";
    for (size_t i = 0; i < Dp; i++) {  //
        Cell c = D[i];
        switch (c.t) {
            case Type::Int:
                os << "int:" << std::dec << c.v.n << ' ';
                break;
            case Type::Hex:
                os << "hex:" << std::hex << c.v.n << ' ';
                break;
            case Type::Oct:
                os << "oct:" << std::oct << c.v.n << ' ';
                break;
            case Type::Bin:
                os << "bin:" << c.v.n << ' ';
                break;
            case Type::Num:
                os << "num:" << c.v.f << ' ';
                break;
            case Type::Obj:
                os << c.v.o->dump(' ');
                break;
            default:
                os << "???:" << c.v.n << ' ';
        }
    }
    os << "]";
    return os.str();
}

void VM::push(int n) {  //
    push({Type::Int, n});
}

void VM::push(Cell c) {
    D[Dp++] = c;
    assert(Dp < Dsz);
}

Cell VM::pop() {
    assert(Dp > 0);
    return D[--Dp];
}

VM vm;
