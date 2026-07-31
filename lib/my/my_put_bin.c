/*
** EPITECH PROJECT, 2025
** my_put_bin
** File description:
** put bin
*/

#include "my.h"

void is_capital_bin(int cap, char **prefix)
{
    if (cap == 1) {
        *prefix = "0B";
    } else {
        *prefix = "0b";
    }
}

int my_put_bin(unsigned nb, int cap, int alt)
{
    char *bin_chars = "01";
    char *prefix = "";
    int count = 0;

    if (alt == 1)
        is_capital_bin(cap, &prefix);
    if (nb == 0) {
        count += my_putstr(prefix);
        count += my_putchar('0');
        return count;
    }
    if (nb >= 2)
        count += my_put_bin(nb / 2, cap, alt);
    count += my_putchar(bin_chars[nb % 2]);
    return count;
}
