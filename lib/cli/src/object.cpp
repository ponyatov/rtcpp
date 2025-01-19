#include "object.hpp"
#include "os.hpp"

// Object *Object::pool = nullptr;

Object::Object() : ref(0) {}
//     next = pool;
//     pool = this;
// }

Object::~Object() { assert(ref == 0); }

void Object::dump(char divider) {  //
    std::cerr << tag() << ':' << val() << divider;
}

std::string Object::tag() { return "object"; }
std::string Object::val() { return ""; }
