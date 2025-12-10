/*
** EPITECH PROJECT, 2025
** my_isneg
** File description:
** Positif or Negatif ?
*/

#include "my.h"

int my_isneg(int nb)
{
    if (nb < 0)
        my_putchar(78);
    else
        my_putchar(80);
    return 0;
}
