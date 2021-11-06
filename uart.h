#pragma once

#include <stdio.h>

void uart_init();
int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);