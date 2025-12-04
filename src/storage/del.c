/*
** EPITECH PROJECT, 2025
** del
** File description:
** File for function delete
*/

#include "../../include/my.h"
#include "../../include/organized.h"
#include "../../include/shell.h"

void free_hw(hardware_t *hw)
{
    char *types[] = {
        "ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE", NULL};

    my_printf("%s n° %d - \"%s\" deleted.\n",
        types[hw->type], hw->id, hw->name);
    free(hw->name);
    free(hw);
}

void dodge_codding_style(linked_list_t *prev, linked_list_t *curr,
    workshop_t *shop)
{
    if (prev == NULL)
        shop->list_head = curr->next;
    else
        prev->next = curr->next;
}

int del_node(workshop_t *shop, int id)
{
    linked_list_t *curr = shop->list_head;
    linked_list_t *prev = NULL;
    hardware_t *hw;

    while (curr != NULL) {
        hw = (hardware_t *)curr->data;
        if (hw->id == id) {
            dodge_codding_style(prev, curr, shop);
            free_hw(hw);
            free(curr);
            return 0;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}

int is_digit(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 84;
}

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
        del_node(shop, id);
    }
    return 0;
}
