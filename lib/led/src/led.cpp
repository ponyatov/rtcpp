#include "led.hpp"

const char LED::tag[] = "led";

LED::LED(Pin *p, Color c) {
    pin = p;
    color = c;
}

LED led(&B5);

void LED::on() {
    state = true;
    dump();
}

void LED::off() {
    state = false;
    dump();
}

void LED::dump(char divider) {  //
    std::cerr << tag << ':' << pin->val() << ';' << val() << divider;
}
