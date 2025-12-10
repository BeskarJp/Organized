/*
** EPITECH PROJECT, 2025
** my_put_ieee.c
** File description:
** print double -> ieee
*/

#include "my.h"

static void is_capital(int cap, ieee754_t *ieee)
{
    if (cap == 1) {
        ieee->hex_base = "0123456789ABCDEF";
        ieee->power_letter = 'P';
        ieee->hexa_indicator = "0X1.";
    } else {
        ieee->hex_base = "0123456789abcdef";
        ieee->power_letter = 'p';
        ieee->hexa_indicator = "0x1.";
    }
}

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

static int find_last(unsigned long long mantisse)
{
    int j = 0;

    for (; j < 13; j++) {
        if ((mantisse & 0xF) != 0)
            return j;
        mantisse >>= 4;
    }
    return 13;
}

static void display_my_put_ieee(ieee754_t *ieee, int *count)
{
    int i = 13;
    int hex_shift = 0;
    int nibble = 0;
    int stop = find_last(ieee->mantisse_bits);

    if (ieee->sign_bit == 1)
        *count += my_putchar('-');
    *count += my_putstr(ieee->hexa_indicator);
    for (; i > stop; i--) {
        hex_shift = (i - 1) * 4;
        nibble = (ieee->mantisse_bits >> hex_shift) & 0xF;
        *count += my_putchar(ieee->hex_base[nibble]);
    }
    *count += my_putchar(ieee->power_letter);
    if (ieee->exponent_bits >= 0)
        *count += my_putchar('+');
    *count += my_put_nbr(ieee->exponent_bits);
}

static int zero_and_one_conditions(double nb, int *count)
{
    if ((nb == 0 && 1 / nb < 0)) {
        *count += my_putstr("-0x0p+0");
        return 1;
    }
    if (nb == 0.0) {
        *count += my_putstr("0x0p+0");
        return 1;
    }
    if (nb == 1.0){
        *count += my_putstr("0x1p+0");
        return 1;
    }
    if (nb == -1.0){
        *count += my_putstr("-0x1p+0");
        return 1;
    }
    return 0;
}

int my_put_ieee(double nb, int cap)
{
    ieee754_t ieee;
    unsigned long long nb_bits = *(unsigned long long *)&nb;
    int count = 0;

    if (special_condition(nb, &count, cap))
        return count;
    is_capital(cap, &ieee);
    ieee.sign_bit = (nb_bits >> 63) & 1;
    ieee.exponent_bits = ((nb_bits >> 52) & 0x7FF) - 1023;
    ieee.mantisse_bits = nb_bits & 0xFFFFFFFFFFFFF;
    if (zero_and_one_conditions(nb, &count))
        return count;
    display_my_put_ieee(&ieee, &count);
    return count;
}
