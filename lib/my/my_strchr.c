/*
** EPITECH PROJECT, 2025
** my_strchr
** File description:
** Find the first occurrence of a character
*/

#include "../../include/my.h"

char *my_strchr(char *buffer, int need)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == (char)need) {
            return &buffer[i];
        }
    }
    if ((char)need == '\0')
        return &buffer[my_strlen(buffer)];
    return NULL;
}
