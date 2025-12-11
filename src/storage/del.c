/*
** EPITECH PROJECT, 2025
** del
** File description:
** File for function delete
*/

#include "my.h"
#include "organized.h"
#include "shell.h"

/**
 * @brief Free a hardware item and print del message.
 *
 * Frees the memory allocated for the hardware element's name and structure
 *
 * @param item
 */
void free_itm(hardware_t *item)
{
    char *types[] = {
        "ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE", NULL};

    print("%s n°%d - \"%s\" deleted.\n",
        types[item->type], item->id, item->name);
    free(item->name);
    free(item);
}

/**
 * @brief Remove node from the linked list.
 *
 * Updates the workshop list head or the previous link to bypass
 * the node being deleted.
 *
 * @param prev
 * @param curr
 * @param shop
 */
void check_null(linked_list_t *prev, linked_list_t *curr,
    workshop_t *shop)
{
    if (prev == NULL)
        shop->list_head = curr->next;
    else
        prev->next = curr->next;
}

/**
 * @brief Delete hardware node from the workshop using his ID.
 *
 * Check workshop list to find the true hardware item.
 * If found, the item and node are freed.
 *
 * @param shop
 * @param id
 * @return int
 */
int del_node(workshop_t *shop, int id)
{
    linked_list_t *curr = shop->list_head;
    linked_list_t *prev = NULL;
    hardware_t *item;

    while (curr != NULL) {
        item = (hardware_t *)curr->data;
        if (item->id == id) {
            check_null(prev, curr, shop);
            free_itm(item);
            free(curr);
            return 0;
        }
        prev = curr;
        curr = curr->next;
    }
    return 84;
}

/**
 * @brief Check if a string contains only digits.
 *
 * @param str
 * @return int
 */
int is_digit(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

/**
 * @brief Check all arguments and remove matching items.
 *
 * Take arguments to an ID and deletes the corresponding node.
 *
 * @param data
 * @param args
 * @return int
 */
int del(void *data, char **args)
{
    workshop_t *shop = (workshop_t *)data;
    int id;

    if (!args || !args[0])
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        if (!is_digit(args[i]))
            return 84;
        id = my_getnbr(args[i]);
        if (del_node(shop, id) == 84)
            return 84;
    }
    return 0;
}
