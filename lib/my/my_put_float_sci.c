/*
** EPITECH PROJECT, 2025
** my_put_float_sci
** File description:
** Flag %e for sci number
*/

#include "my.h"

static int go_to_coma(double *nb)
{
    int count = 0;

    if (*nb == 0.0)
        return 0;
    while (*nb >= 10.0) {
        *nb = *nb / 10;
        count++;
    }
    while (*nb < 1.0 && *nb > 0.0) {
        *nb = *nb * 10;
        count--;
    }
    return count;
}

void go_to_round(double nb, char *str)
{
    int i;
    int digit;

    nb = nb - (int)nb;
    for (i = 0; i < 6; i++) {
        nb = nb * 10;
        digit = (int)nb;
        str[i] = digit + '0';
        nb = nb - digit;
    }
    str[i] = '\0';
}

int display_sci(int count, int *count_put)
{
    if (count >= 0)
        *count_put += my_putchar('+');
    else {
        *count_put += my_putchar('-');
        count = -count;
    }
    if (count <= 9)
        *count_put += my_putchar('0');
    *count_put += my_put_nbr(count);
    return *count_put;
}

static int display_zero(int cap, int *count_put)
{
    *count_put += my_putstr("0.000000");
    *count_put += my_putchar(cap ? 'E' : 'e');
    *count_put += my_putstr("+00");
    return *count_put;
}

static int my_sci_process(double nb, int cap, int *count_put)
{
    char rounded[7];
    int exponent;

    exponent = go_to_coma(&nb);
    nb = nb + 0.0000005;
    if (nb >= 10.0) {
        nb = nb / 10;
        exponent++;
    }
    *count_put += my_put_nbr((int)nb);
    *count_put += my_putchar('.');
    go_to_round(nb, rounded);
    *count_put += my_putstr(rounded);
    *count_put += my_putchar(cap ? 'E' : 'e');
    return display_sci(exponent, count_put);
}

int my_put_float_sci(double nb, int cap)
{
    int count_put = 0;
    double one = 1.0;

    if (one / nb < 0) {
        count_put += my_putchar('-');
        nb = -nb;
    }
    if (nb == 0.0)
        return display_zero(cap, &count_put);
    return my_sci_process(nb, cap, &count_put);
}
