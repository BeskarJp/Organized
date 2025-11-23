/*
** EPITECH PROJECT, 2025
** my_str_isalpha
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
