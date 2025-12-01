/*
** EPITECH PROJECT, 2025
** add
** File description:
** File for function add
*/

#include "../include/my.h"
#include "../include/organized.h"
#include "../include/shell.h"

int add_single_hardware(workshop_t *ws, char *type, char *name)
{
    hardware_t *new_hardware;

    if (!type || !name)
        return 84;
    new_hardware = (hardware_t *)malloc(sizeof(hardware_t));
    if (!new_hardware)
        return 84;
    new_hardware->type = my_strdup(type);
    new_hardware->name = my_strdup(name);
    new_hardware->id = ws->next_id;
    push_to_list(&(ws->list_head), new_hardware);
    my_putstr(new_hardware->type);
    my_putstr(" n°");
    my_put_nbr(new_hardware->id);
    my_putstr(" \"");
    my_putstr(new_hardware->name);
    my_putstr("\" added.\n");
    ws->next_id++;
    return 0;
}

int add(void *data, char **args)
{
    workshop_t *ws = (workshop_t *)data;
    char **elements;
    char **hardware_parts;
    int ret = 0;

    if (!args || !args[0])
        return 84;
    elements = my_str_to_word_array(args[0]);
    if (!elements)
        return 84;
    for (int i = 0; elements[i] && ret == 0; i++) {
        hardware_parts = my_str_to_word_array(elements[i]);
        if (hardware_parts && hardware_parts[0] && hardware_parts[1]) {
            ret = add_single_hardware(ws, hardware_parts[0], hardware_parts[1]);
        } else {
            ret = 84;
        }
    }
    return 0;
}
