/*
** EPITECH PROJECT, 2025
** my_put_hex
** File description:
** put hex
*/

#include "my.h"

int my_put_hex(unsigned nb, int cap)
{
    char *hex_chars = "0123456789abcdef";
    char *hex_chars_cap = "0123456789ABCDEF";
    int count = 0;

    if (nb >= 16) {
        count += my_put_hex(nb / 16, cap);
    }
    if (cap == 1) {
        count += my_putchar(hex_chars_cap[nb % 16]);
    } else {
        count += my_putchar(hex_chars[nb % 16]);
    }
    return count;
}
