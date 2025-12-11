/*
** EPITECH PROJECT, 2025
** add
** File description:
** File for function adding
*/

#include "my.h"
#include "organized.h"
#include "shell.h"

/**
 * @brief Get the type id object and ID
 *
 * Compares the type string in command with the list of valid types
 * and returns his index.
 *
 * @param type
 * @return int
 */
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

/**
 * @brief Create a new hardware item and insert to the workshop list.
 *
 * Allocates and initializes hardware struct and linked list node.
 * The new item is inserted at the beginning of the workshop list.
 *
 * @param shop
 * @param type
 * @param name
 * @return int
 */
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

/**
 * @brief Adding new hardware items with his type and ID.
 *
 * Reads arguments in two (type and name) and pushes the item to workshop.
 *
 * @param data
 * @param args
 * @return int
 */
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
