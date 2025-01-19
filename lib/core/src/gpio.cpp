#include "gpio.hpp"
#include "os.hpp"

Port::Port(std::string name) : name(name) {}

std::string Port::tag() { return "port"; }
std::string Port::val() { return name; }

Port A("A");
Port B("B");
Port C("C");
Port D("D");

Pin::Pin(Port *port, PinIndex index) {  //
    port = port;
    port->ref++;
    index = index;
}

std::string Pin::tag() { return "pin"; }
std::string Pin::val() {
    std::ostringstream os;
    os << index;
    return os.str();
}

Pin B5(&B, 5);
