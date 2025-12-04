/*
** EPITECH PROJECT, 2025
** disp
** File description:
** File for function display
*/

#include "../../include/my.h"
#include "../../include/organized.h"
#include "../../include/shell.h"

int disp(void *data, char **args)
{
    workshop_t *shop = (workshop_t *)data;
    linked_list_t *curr = shop->list_head;
    hardware_t *itm;
    char *types[] = {
        "ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE", NULL};

    (void)args;
    while (curr != NULL) {
        itm = (hardware_t *)curr->data;
        my_printf("%s n°%d - \"%s\"\n", types[itm->type], itm->id, itm->name);
        curr = curr->next;
    }
    return 0;
}
