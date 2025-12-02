/*
** EPITECH PROJECT, 2025
** add
** File description:
** File for function add
*/

#include "../../include/my.h"
#include "../../include/organized.h"
#include "../../include/shell.h"

int get_type_id(char *type)
{
    char *types[] = {
        "ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE", NULL};

    for (int i = 0; types[i] != NULL; i++) {
        if (my_strcmp(type, types[i]) == 0)
            return i;
    }
    return -1;
}

int create_hw(workshop_t *shop, char *type, char *name)
{
    hardware_t *hw;
    linked_list_t *node;
    int type_id = get_type_id(type);
    char *types[] = {
        "ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE", NULL};

    if (type_id == -1)
        return 84;
    hw = malloc(sizeof(hardware_t));
    node = malloc(sizeof(linked_list_t));
    if (!hw || !node || !(hw->name = my_strdup(name)))
        return 84;
    hw->type = type_id;
    hw->id = shop->next_id++;
    node->data = hw;
    node->next = shop->list_head;
    shop->list_head = node;
    my_printf("%s n°%d - \"%s\" added.\n", types[type_id], hw->id, hw->name);
    return 0;
}

int add(void *data, char **args)
{
    workshop_t *shop = (workshop_t *)data;
    int i = 0;

    if (!args || !args[0])
        return 84;
    while (args[i] != NULL) {
        if (args[i + 1] == NULL)
            return 84;
        if (create_hw(shop, args[i], args[i + 1]) == 84)
            return 84;
        i += 2;
    }
    return 0;
}
