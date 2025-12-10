/*
** EPITECH PROJECT, 2025
** organized
** File description:
** Main of project
*/

#include "my.h"
#include "organized.h"
#include "shell.h"

/**
 * @brief Main entry point of the program.
 *
 * Initializes the workshop data structure and launches the shell
 * with workshop_shell
 *
 * @return int
 */
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
