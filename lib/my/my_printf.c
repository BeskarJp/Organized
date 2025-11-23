/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** main file
*/

#include <stdarg.h>
#include "../../include/my.h"

static void follow_percent_nb_four(char nxt_c, va_list list, int *count)
{
    switch (nxt_c) {
        case 'b':
            *count += my_put_bin(va_arg(list, int), 0, 0);
            break;
        default:
            *count += my_putchar('%');
            *count += my_putchar(nxt_c);
            break;
    }
}

static void follow_percent_tempname(char nxt_c, va_list list, int *count)
{
    switch (nxt_c) {
        case 'A':
            *count += my_put_ieee(va_arg(list, double), 1);
            break;
        case 'F':
            *count += my_put_float(va_arg(list, double), 1, 1);
            break;
        case 'E':
            *count += my_put_float_sci(va_arg(list, double), 1);
            break;
        case 'B':
            *count += my_put_bin(va_arg(list, int), 1, 0);
            break;
        default:
            follow_percent_nb_four(nxt_c, list, count);
    }
}

static void follow_percent_ter(char nxt_c, va_list list, int *count)
{
    switch (nxt_c) {
        case 'p':
            *count += my_put_pointer(va_arg(list, unsigned long));
            break;
        case 'u':
            *count += my_put_nbr_uint(va_arg(list, unsigned int));
            break;
        case 'e':
            *count += my_put_float_sci(va_arg(list, double), 0);
            break;
        case 'a':
            *count += my_put_ieee(va_arg(list, double), 0);
            break;
        default:
            follow_percent_tempname(nxt_c, list, count);
    }
}

static void follow_percent_bis(char nxt_c, va_list list, int *count)
{
    switch (nxt_c) {
        case 'x':
            *count += my_put_hex(va_arg(list, int), 0);
            break;
        case 'X':
            *count += my_put_hex(va_arg(list, int), 1);
            break;
        case 'f':
            *count += my_put_float(va_arg(list, double), 6, 0);
            break;
        case 'o':
            *count += my_put_oct(va_arg(list, int));
            break;
        default:
            follow_percent_ter(nxt_c, list, count);
            break;
    }
}

static void follow_percent(char nxt_c, va_list list, int *count)
{
    switch (nxt_c) {
        case '%':
            *count += my_putchar('%');
            break;
        case 'c':
            *count += my_putchar(va_arg(list, int));
            break;
        case 's':
            *count += my_putstr(va_arg(list, char*));
            break;
        case 'i':
        case 'd':
            *count += my_put_nbr(va_arg(list, int));
            break;
        default:
            follow_percent_bis(nxt_c, list, count);
            break;
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    int count = 0;

    va_start(list, format);
    for (; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            follow_percent(format[i + 1], list, &count);
            i++;
        } else {
            count += my_putchar(format[i]);
        }
    }
    va_end(list);
    return count;
}
