/*
** EPITECH PROJECT, 2025
** algo
** File description:
** File for the algorithm
*/

#include "../../include/my.h"
#include "../../include/organized.h"
#include "../../include/shell.h"

int cmp_vals(hardware_t *item_one, hardware_t *item_two, sort_info_t *infos)
{
    int res = 0;

    if (infos->type == TYPE)
        res = item_one->type - item_two->type;
    if (infos->type == NAME)
        res = my_strcmp(item_one->name, item_two->name);
    if (infos->type == ID)
        res = item_one->id - item_two->id;
    if (infos->is_reverse)
        return -res;
    return res;
}

int should_swap(hardware_t *item_one, hardware_t *item_two, sort_info_t *infos)
{
    int res = 0;

    for (int i = 0; i < 3 && infos[i].type != UNKNOWN; i++) {
        res = cmp_vals(item_one, item_two, &infos[i]);
        if (res != 0)
            return (res > 0);
    }
    return 0;
}

void swap_data(linked_list_t *item_one, linked_list_t *item_two)
{
    void *temp;

    temp = item_one->data;
    item_one->data = item_two->data;
    item_two->data = temp;
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
