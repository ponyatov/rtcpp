#include "led.hpp"

LED::LED(Pin *p, Color c) {
    pin = p;
    color = c;
}

LED led(&B5);

void LED::on() {
    state = true;
    pin->on();
    std::cerr << dump(' ') << "/ on" << std::endl;
}

void LED::off() {
    state = false;
    pin->off();
    std::cerr << dump(' ') << "/ off" << std::endl;
}

std::string LED::tag() { return "led"; }
std::string LED::val() {
    std::ostringstream os;
    os << state;
    return os.str();
}
