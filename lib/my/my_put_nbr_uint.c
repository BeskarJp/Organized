/*
** EPITECH PROJECT, 2025
** my_put_nbr_unit
** File description:
** Fonction which is doing an unsigned int
*/

#include "my.h"

int my_put_nbr_uint(unsigned int nb)
{
    int count = 0;

    if (nb >= 10)
        count += my_put_nbr_uint(nb / 10);
    count += my_putchar('0' + (nb % 10));
    return count;
}
