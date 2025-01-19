#include "led.hpp"
#include "os.hpp"

LED::LED(Pin *pin, Color color, LEDState state) : pin(pin), color(color) {
    if (state == LEDState::ON)
        on();
    else
        off();
}

void LED::dump(char divider) { std::cerr << "led:" << (bool)state << divider; }

LED led(&B5);

void LED::on() {
    state = LEDState::ON;
    pin->on();
    dump();
}

void LED::off() {
    state = LEDState::OFF;
    pin->off();
    dump();
}

// std::string LED::tag() { return "led"; }
// std::string LED::val() {
//     std::ostringstream os;
//     os << state;
//     return os.str();
// }
