/*
** EPITECH PROJECT, 2025
** my_strncpy
** File description:
** Copy a string at n size
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n; i++)
        dest[i] = src[i];
    return dest;
}
