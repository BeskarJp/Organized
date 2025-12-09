/*
** EPITECH PROJECT, 2025
** add
** File description:
** File for function adding
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

int create_item(workshop_t *shop, char *type, char *name)
{
    hardware_t *item = malloc(sizeof(hardware_t));
    linked_list_t *node = malloc(sizeof(linked_list_t));
    int type_id = get_type_id(type);
    char *types[] = {
        "ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE", NULL};

    item->name = my_strdup(name);
    if (!item || !node || !item->name || type_id == -1)
        return 84;
    item->type = type_id;
    item->id = shop->next_id;
    shop->next_id = shop->next_id + 1;
    node->data = item;
    node->next = shop->list_head;
    shop->list_head = node;
    print("%s n°%d - \"%s\" added.\n", types[type_id], item->id, item->name);
    return 0;
}

int add(void *data, char **args)
{
    workshop_t *shop = (workshop_t *)data;

    if (!args || !args[0])
        return 84;
    for (int i = 0; args[i] != NULL; i += 2) {
        if (args[i + 1] == NULL)
            return 84;
        if (create_item(shop, args[i], args[i + 1]) == 84)
            return 84;
    }
    return 0;
}
