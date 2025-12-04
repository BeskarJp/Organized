/*
** EPITECH PROJECT, 2025
** sort
** File description:
** File for function sorting stuff
*/

#include "../../include/my.h"
#include "../../include/organized.h"
#include "../../include/shell.h"

static void init_infos(sort_info_t *infos)
{
    for (int i = 0; i < 4; i++) {
        infos[i].type = UNKNOWN;
        infos[i].is_reverse = 0;
    }
}

int set_criteria(char *arg, sort_info_t *infos, int idx)
{
    if (my_strcmp(arg, "TYPE") == 0) {
        infos[idx].type = TYPE;
        return 0;
    }
    if (my_strcmp(arg, "NAME") == 0) {
        infos[idx].type = NAME;
        return 0;
    }
    if (my_strcmp(arg, "ID") == 0) {
        infos[idx].type = ID;
        return 0;
    }
    return 84;
}

int handle_reverse(sort_info_t *infos, int idx)
{
    if (idx == 0)
        return 84;
    infos[idx - 1].is_reverse = 1;
    return 0;
}

int handle_criterion(char *arg, sort_info_t *infos, int *idx)
{
    if (*idx >= 3)
        return 84;
    if (set_criteria(arg, infos, *idx) == 84)
        return 84;
    (*idx)++;
    return 0;
}

int parse_args(char **args, sort_info_t *infos)
{
    int idx = 0;
    int error = 0;

    for (int i = 0; args[i] != NULL; i++) {
        if (my_strcmp(args[i], "-r") == 0)
            error = handle_reverse(infos, idx);
        else
            error = handle_criterion(args[i], infos, &idx);
        if (error == 84)
            return 84;
    }
    if (idx == 0)
        return 84;
    return 0;
}

int sort(void *data, char **args)
{
    workshop_t *shop = (workshop_t *)data;
    sort_info_t infos[4];

    if (!args || !args[0])
        return 84;
    init_infos(infos);
    if (parse_args(args, infos) == 84)
        return 84;
    bubble_sort(shop->list_head, infos);
    return 0;
}
