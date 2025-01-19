#include "gpio.hpp"
#include "os.hpp"

Port::Port(char name) : name(name) {}

void Port::dump(char divider) { std::cerr << "port:" << name << divider; }

Port A('A');
Port B('B');
Port C('C');
Port D('D');

Pin::Pin(Port* port, PinIndex index, PinState state)
    : port(port), index(index), state(state) {}

static const char* pinstate_[] = {"high", "low", "input"};

void Pin::dump(char divider) {
    std::cerr << "pin:" << pinstate_[(int)state] << divider;
}

void Pin::on() {
    state = PinState::HIGH;
    dump();
}

void Pin::off() {
    state = PinState::LOW;
    dump();
}

Pin B5(&B, 5);
