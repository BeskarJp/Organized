/*
** EPITECH PROJECT, 2025
** algo
** File description:
** File for the algorithm
*/

#include "../../include/my.h"
#include "../../include/organized.h"
#include "../../include/shell.h"

int cmp_vals(hardware_t *a, hardware_t *b, sort_info_t *info)
{
    int res = 0;

    if (info->type == TYPE)
        res = a->type - b->type;
    if (info->type == NAME)
        res = my_strcmp(a->name, b->name);
    if (info->type == ID)
        res = a->id - b->id;
    if (info->is_reverse)
        return -res;
    return res;
}

int should_swap(hardware_t *a, hardware_t *b, sort_info_t *infos)
{
    int res = 0;

    for (int i = 0; i < 3 && infos[i].type != UNKNOWN; i++) {
        res = cmp_vals(a, b, &infos[i]);
        if (res != 0)
            return (res > 0);
    }
    return 0;
}

void swap_data(linked_list_t *a, linked_list_t *b)
{
    void *temp;

    temp = a->data;
    a->data = b->data;
    b->data = temp;
}

int bubble_sort_pass(linked_list_t *list, sort_info_t *infos)
{
    linked_list_t *curr = list;
    int swapped = 0;

    while (curr->next != NULL) {
        if (should_swap(curr->data, curr->next->data, infos)) {
            swap_data(curr, curr->next);
            swapped = 1;
        }
        curr = curr->next;
    }
    return swapped;
}

void bubble_sort(linked_list_t *list, sort_info_t *infos)
{
    int swapped = 1;

    if (!list)
        return;
    while (swapped)
        swapped = bubble_sort_pass(list, infos);
}
