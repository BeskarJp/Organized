/*
** EPITECH PROJECT, 2025
** my_compute_power_rec
** File description:
** Number with any power in it
*/

int my_compute_power_rec(int nb, int p)
{
    int result = nb;

    if (p < 0)
        return 0;
    else if (p == 0)
        return 1;
    else
        result = nb * my_compute_power_rec(nb, p - 1);
    return result;
}
