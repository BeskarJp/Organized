/*
** EPITECH PROJECT, 2025
** organized
** File description:
** Main of project
*/

#include "../include/my.h"
#include "../include/organized.h"
#include "../include/shell.h"

int main(void)
{
    workshop_t workshop_data = {NULL, 0};
    int status = 0;

    status = workshop_shell(&workshop_data);
    free_workshop_data(&workshop_data);
    if (status == 84)
        return 84;
    return 0;
}
