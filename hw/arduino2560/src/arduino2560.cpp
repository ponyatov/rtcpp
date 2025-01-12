#include "led.hpp"
#include "gpio.hpp"

Port8 B = Port8('B');

Pin led_pin = Pin(B, 7, State::LOW);

LED led = LED(led_pin, Color::GREEN);
