/*
** EPITECH PROJECT, 2025
** disp
** File description:
** File for function display
*/

#include "my.h"
#include "organized.h"
#include "shell.h"

/**
 * @brief Displays the list of all hardware items in the workshop
 *
 * This function analyze the linked list of hardware items
 * and prints the type, ID, and name of each item
 *
 * @param data
 * @param args
 * @return int
 */
int disp(void *data, char **args)
{
    workshop_t *shop = (workshop_t *)data;
    linked_list_t *curr = shop->list_head;
    hardware_t *item;
    char *types[] = {
        "ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE", NULL};

    (void)args;
    while (curr != NULL) {
        item = (hardware_t *)curr->data;
        print("%s n°%d - \"%s\"\n", types[item->type], item->id, item->name);
        curr = curr->next;
    }
    return 0;
}
