/*
** EPITECH PROJECT, 2025
** my_swap
** File description:
** Change an adresse
*/

void my_swap(int *a, int *b)
{
    int tempo = 0;

    tempo = *b;
    *b = *a;
    *a = tempo;
}
