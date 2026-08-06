#include <avr/io.h> // Hardware-specific registry header

int main(void) {
    DDRB |= (1 << PB5);    // Set pin 5 of Port B as an output register
    PORTB |= (1 << PB5);   // Drive pin 5 high to turn on an LED
    while(1);              // Superloop keeping the MCU running
}
