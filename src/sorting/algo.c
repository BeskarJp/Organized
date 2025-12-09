/*
** EPITECH PROJECT, 2025
** algo
** File description:
** Quick sort algorithm
*/

#include "../../include/my.h"
#include "../../include/organized.h"
#include "../../include/shell.h"

int cmp_vals(hardware_t *first_item, hardware_t *sec_item, sort_info_t *infos)
{
    int compare = 0;

    if (infos->type == TYPE)
        compare = first_item->type - sec_item->type;
    if (infos->type == NAME)
        compare = my_strcmp(first_item->name, sec_item->name);
    if (infos->type == ID)
        compare = first_item->id - sec_item->id;
    if (infos->is_reverse)
        return -compare;
    return compare;
}

int should_swap_items(hardware_t *first_item, hardware_t *sec_item,
    sort_info_t *infos)
{
    int compare = 0;

    for (int i = 0; i < 3 && infos[i].type != UNKNOWN; i++) {
        compare = cmp_vals(first_item, sec_item, &infos[i]);
        if (compare != 0)
            return (compare > 0);
    }
    return 0;
}

void swap_data(linked_list_t *first_item, linked_list_t *sec_item)
{
    void *temp;

    temp = first_item->data;
    first_item->data = sec_item->data;
    sec_item->data = temp;
}

static linked_list_t *partition_list(linked_list_t *start_node,
    linked_list_t *pivot_node, sort_info_t *infos)
{
    hardware_t *pivot = (hardware_t *)pivot_node->data;
    linked_list_t *store = start_node;
    linked_list_t *current = start_node;

    while (current != pivot_node && current != NULL) {
        if (should_swap_items(pivot, (hardware_t *)current->data, infos)) {
            swap_data(store, current);
            store = store->next;
        }
        current = current->next;
    }
    swap_data(store, pivot_node);
    return (store);
}

void quick_sort_recursive(linked_list_t *start_node, linked_list_t *end_node,
    sort_info_t *infos)
{
    linked_list_t *last_pivot;
    linked_list_t *before_pivot;

    if (end_node != NULL && start_node != end_node &&
        start_node != end_node->next) {
        last_pivot = partition_list(start_node, end_node, infos);
        before_pivot = start_node;
        while (before_pivot != NULL && before_pivot->next != last_pivot)
            before_pivot = before_pivot->next;
        quick_sort_recursive(start_node, before_pivot, infos);
        quick_sort_recursive(last_pivot->next, end_node, infos);
    }
}

void quick_sort(linked_list_t *list, sort_info_t *infos)
{
    linked_list_t *last_node = list;

    if (!list || !list->next)
        return;
    while (last_node->next != NULL)
        last_node = last_node->next;
    quick_sort_recursive(list, last_node, infos);
}
