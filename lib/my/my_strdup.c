/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** my_strdup
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int len;
    int i = 0;
    char *dest;

    if (!src)
        return NULL;
    len = my_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    for (; i < len; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
