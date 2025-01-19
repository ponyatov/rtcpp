#include "gpio.hpp"
#include "os.hpp"

Port::Port(std::string name) : name(name) {}

std::string Port::tag() { return "port"; }
std::string Port::val() { return name; }

void Port::on() {}
void Port::off() {}

Port A("A");
Port B("B");
Port C("C");
Port D("D");

const char *pinstate_[] = {"high", "low", "input"};

Pin::Pin(Port *port, PinIndex index) : port(port), index(index) {}

std::string Pin::tag() { return "pin"; }
std::string Pin::val() {
    std::ostringstream os;
    os << port->val() << (int)index << ':' << pinstate_[(int)state];
    return os.str();
}

void Pin::on() {
    state = PinState::HIGH;
    std::cerr << dump();
}

void Pin::off() {
    state = PinState::LOW;
    std::cerr << dump();
}

Pin B5(&B, 5);
