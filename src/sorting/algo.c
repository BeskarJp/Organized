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

static linked_list_t *partition(linked_list_t *low, linked_list_t *high,
    sort_info_t *infos)
{
    hardware_t *pivot = (hardware_t *)high->data;
    linked_list_t *i = low;
    linked_list_t *j = low;

    while (j != high && j != NULL) {
        if (should_swap(pivot, (hardware_t *)j->data, infos)) {
            swap_data(i, j);
            i = i->next;
        }
        j = j->next;
    }
    swap_data(i, high);
    return (i);
}

void quick_sort_recursive(linked_list_t *low, linked_list_t *high,
    sort_info_t *infos)
{
    linked_list_t *p;
    linked_list_t *curr;

    if (high != NULL && low != high && low != high->next) {
        p = partition(low, high, infos);
        curr = low;
        while (curr != NULL && curr->next != p)
            curr = curr->next;
        quick_sort_recursive(low, curr, infos);
        quick_sort_recursive(p->next, high, infos);
    }
}

void quick_sort(linked_list_t *list, sort_info_t *infos)
{
    linked_list_t *last = list;

    if (!list || !list->next)
        return;
    while (last->next != NULL)
        last = last->next;
    quick_sort_recursive(list, last, infos);
}
