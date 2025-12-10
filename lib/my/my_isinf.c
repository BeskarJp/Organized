/*
** EPITECH PROJECT, 2025
** my_isinf.c
** File description:
** is that number inf ?
*/

#include "my.h"

int my_isinf(double nb)
{
    if (nb == 1.0 / 0.0 || nb == -1.0 / 0.0)
        return 1;
    return 0;
}
