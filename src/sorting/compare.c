/*
** EPITECH PROJECT, 2025
** sort
** File description:
** File for function sorting stuff
*/

#include "../../include/my.h"
#include "../../include/organized.h"
#include "../../include/shell.h"

int compare_name(hardware_t *a, hardware_t *b, int reverse)
{
    int result = my_strcmp(a->name, b->name);

    return (reverse ? -result : result);
}

int compare_type(hardware_t *a, hardware_t *b, int reverse)
{
    int result = a->type - b->type;

    return (reverse ? -result : result);
}

int compare_id(hardware_t *a, hardware_t *b, int reverse)
{
    int result = a->id - b->id;

    return (reverse ? -result : result);
}
