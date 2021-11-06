#pragma once

#include <stdio.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#ifndef BAUD
#define BAUD 9600
#endif

void uart_init();
int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);
void uart_puts(char* s);
