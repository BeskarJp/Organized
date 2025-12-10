/*
** EPITECH PROJECT, 2025
** my_putfloat.c
** File description:
** print a float
*/

#include "my.h"

static int special_condition(double nb, int *count, int cap)
{
    if (my_isnan(nb)) {
        if (cap == 1)
            *count += my_putstr("NAN");
        else
            *count += my_putstr("nan");
        return 1;
    }
    if (my_isinf(nb)) {
        if (nb < 0)
            *count += my_putchar('-');
        if (cap == 1)
            *count += my_putstr("INF");
        else
            *count += my_putstr("inf");
        return 1;
    }
    return 0;
}

static void display_loop(double rest, int prec, int *count)
{
    int i = 0;

    for (; i < prec; i++) {
        rest *= 10.0;
        *count += my_putchar('0' + (int)rest);
        rest -= (int)rest;
    }
}

int my_put_float(double nb, int prec, int cap)
{
    int count = 0;
    int inte_part;
    double rest;
    double round = 0.5;

    if (special_condition(nb, &count, cap))
        return count;
    if (nb < 0 || (nb == 0 && 1 / nb < 0)) {
        count += my_putchar('-');
        nb = -nb;
    }
    for (int j = 0; j < prec; j++)
        round /= 10.0;
    inte_part = (int)nb;
    rest = nb - (double)inte_part + round;
    count += my_put_nbr(inte_part);
    count += my_putchar('.');
    display_loop(rest, prec, &count);
    return count;
}
