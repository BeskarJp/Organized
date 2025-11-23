/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** Include of Lib
*/

#ifndef MY
    #define MY

    #include <stdlib.h>
    #include <stdio.h>

typedef struct ieee754_double {
    unsigned long long nb_bits;
    int sign_bit;
    int exponent_bits;
    unsigned long long mantisse_bits;
    char *hex_base;
    int hex_shift;
    int hex_bits;
    char power_letter;
    char *hexa_indicator;
} ieee754_t;

int my_compute_power_rec(int nb, int power);
int my_getnbr(char *str);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_str_isalpha(char c);
char **my_str_to_word_array(const char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char my_strmcp(char const *str_one, char const *str_two, int nb);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
void my_swap(int *a, int *b);
int my_isinf(double nb);
int my_isnan(double nb);
int my_put_bin(unsigned nb, int cap, int alt);
int my_put_float_sci(double nb, int cap);
int my_put_float(double nb, int prec, int cap);
int my_put_hex(unsigned nb, int cap);
int my_put_ieee(double nb, int cap);
int my_put_nbr_uint(unsigned int nb);
int my_put_oct(unsigned nb);
int my_put_pointer(unsigned long nb);
int my_printf(const char *format, ...);

#endif /* MY */
