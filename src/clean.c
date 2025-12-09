/*
** EPITECH PROJECT, 2025
** organized
** File description:
** Main of project
*/

#include "../include/my.h"
#include "../include/organized.h"
#include "../include/shell.h"

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
