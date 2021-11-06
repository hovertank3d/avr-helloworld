#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include "uart.h"

int main()
{
    uint32_t num;
    uart_init();
    while (1) {
        printf("Write a number:\n");
        scanf("%ld", &num);
        uart_putchar('\n', stdout);

        while (num > 1) {
            printf("[%ld]", num);
            num = (num & 1) ? 3 * num + 1 : num / 2;
        }
        printf("[1]\n");
    }
    return 0;
}