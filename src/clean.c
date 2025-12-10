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
 * @brief Frees all dynamically allocated memory
 *
 * Explore the linked list, freeing the item name, the item structure,
 * and the list node for all entries.
 *
 * @param shop
 */
void free_workshop_data(workshop_t *shop)
{
    linked_list_t *curr = shop->list_head;
    linked_list_t *next_node;
    hardware_t *item;

    while (curr != NULL) {
        next_node = curr->next;
        item = (hardware_t *)curr->data;
        free(item->name);
        free(item);
        free(curr);
        curr = next_node;
    }
    shop->list_head = NULL;
}
