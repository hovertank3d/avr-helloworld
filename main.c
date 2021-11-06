#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>

#include "uart.h"

int main()
{
    uint32_t num;
    uart_init();

    printf("Write a number:\n");
    scanf("%lu", &num);
    putchar('\n');

    printf("[%lu", num);
    while (num > 1)
    {
        num = (num & 1) ? 3 * num + 1 : num / 2;
        printf(", %lu", num);
    }
    putchar(']');
    return 0;
}