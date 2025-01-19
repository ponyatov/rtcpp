#include "gpio.hpp"

Port::Port(char name) : name(name) {}

Port A('A');
Port B('B');
Port C('C');
Port D('D');

Pin::Pin(Port *port, PinIndex pin) : port(port), pin(pin) {}

Pin B5(&B, 5);
