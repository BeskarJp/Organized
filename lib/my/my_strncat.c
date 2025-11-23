/*
** EPITECH PROJECT, 2025
** my_strncat
** File description:
** my_strncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++) {
    }
    for (; j < nb && src[j]; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
