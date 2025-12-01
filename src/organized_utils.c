/*
** EPITECH PROJECT, 2025
** organized
** File description:
** Main of project
*/

#include "../include/my.h"
#include "../include/organized.h"
#include "../include/shell.h"

void push_to_list(linked_list_t **begin, void *data)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));

    if (!new_node)
        return;
    new_node->data = data;
    new_node->next = *begin;
    *begin = new_node;
}
