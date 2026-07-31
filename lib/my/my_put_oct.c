/*
** EPITECH PROJECT, 2025
** my_put_oct.c
** File description:
** pas d'inspi
*/

#include "my.h"
#include <stdio.h>

int my_put_oct(unsigned nb)
{
    char *hex_chars = "01234567";
    int count = 0;

    if (nb >= 8) {
        count += my_put_oct(nb / 8);
    }
    count += my_putchar(hex_chars[nb % 8]);
    return count;
}
