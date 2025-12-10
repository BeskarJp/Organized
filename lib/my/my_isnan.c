/*
** EPITECH PROJECT, 2025
** my_isnan.c
** File description:
** is that a real number ?
*/

#include "my.h"

int my_isnan(double nb)
{
    if (nb != nb) {
        return 1;
    }
    return 0;
}
