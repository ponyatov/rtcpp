#include "led.hpp"

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
