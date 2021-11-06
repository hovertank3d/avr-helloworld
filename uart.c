#include <stdio.h>
#include <avr/io.h>

#define BAUD 9600
#include <util/setbaud.h>

#include "uart.h"

FILE _stdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
FILE _stdin = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);

void uart_init()
{
    stdout = &_stdout;
    stdin = &_stdin;
    UBRR0 = UBRR_VALUE;
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);

    uart_putchar('\r', stdout);
}

int uart_putchar(char c, FILE *stream)
{
    if (c == '\n')
        uart_putchar('\r', stream);
    loop_until_bit_is_set(UCSR0A, UDRE0);
    return UDR0 = c;
}

int uart_getchar(FILE *stream)
{
    if(!stream)   
        return EOF;
    loop_until_bit_is_set(UCSR0A, RXC0);
    return uart_putchar(UDR0, stdout);
}