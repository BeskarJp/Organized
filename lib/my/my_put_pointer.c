/*
** EPITECH PROJECT, 2025
** my_put_pointer.c
** File description:
** display pointer in hexa
*/

#include "my.h"

static int my_put_pointer_hex(unsigned long nb, int *count)
{
    char *hex = "0123456789abcdef";

    if (nb >= 16) {
        my_put_pointer_hex(nb / 16, count);
    }
    *count += my_putchar(hex[nb % 16]);
    return *count;
}

int my_put_pointer(unsigned long nb)
{
    int count = 0;

    if (nb == 0) {
        return my_putstr("(nil)");
    }
    count += my_putstr("0x");
    my_put_pointer_hex(nb, &count);
    return count;
}
