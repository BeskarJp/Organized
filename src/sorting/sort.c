/*
** EPITECH PROJECT, 2025
** sort
** File description:
** File for function sorting stuff
*/

#include "my.h"
#include "organized.h"
#include "shell.h"

/**
 * @brief Initialize sorting struct.
 *
 * Sets all sort_info_t entries to UNKNOWN type and disables reverse mode.
 *
 * @param infos
 */
static void initialize_struct_infos(sort_info_t *infos)
{
    for (int i = 0; i < 4; i++) {
        infos[i].type = UNKNOWN;
        infos[i].is_reverse = 0;
    }
}

/**
 * @brief Assign a sorting by the given token.
 *
 * Matches the token with valid criteria and
 * updates the corresponding struct entry.
 *
 * @param token
 * @param infos
 * @param idx
 * @return int
 */
int set_criteria(char *token, sort_info_t *infos, int idx)
{
    if (my_strcmp(token, "TYPE") == 0) {
        infos[idx].type = TYPE;
        return 0;
    }
    if (my_strcmp(token, "NAME") == 0) {
        infos[idx].type = NAME;
        return 0;
    }
    if (my_strcmp(token, "ID") == 0) {
        infos[idx].type = ID;
        return 0;
    }
    return 84;
}

/**
 * @brief Make the sort in reverse.
 *
 * Apply the reverse sort with '-r' flag.
 *
 * @param infos
 * @param idx
 * @return int
 */
int handle_reverse(sort_info_t *infos, int idx)
{
    if (idx == 0)
        return 84;
    infos[idx - 1].is_reverse = 1;
    return 0;
}

/**
 * @brief Register a sorting criterion.
 *
 * Check if the index is valid, sets criterion and increments the index.
 *
 * @param token
 * @param infos
 * @param idx
 * @return int
 */
int handle_criterion(char *token, sort_info_t *infos, int *idx)
{
    if (*idx >= 3)
        return 84;
    if (set_criteria(token, infos, *idx) == 84)
        return 84;
    (*idx)++;
    return 0;
}

/**
 * @brief Parse sorting tokens and fill the criteria array.
 *
 * Register one by one the criteria after sort's command.
 *
 * @param token
 * @param infos
 * @return int
 */
int parse_token(char **token, sort_info_t *infos)
{
    int idx = 0;
    int error = 0;

    for (int i = 0; token[i] != NULL; i++) {
        if (my_strcmp(token[i], "-r") == 0)
            error = handle_reverse(infos, idx);
        else
            error = handle_criterion(token[i], infos, &idx);
        if (error == 84)
            return 84;
    }
    if (idx == 0)
        return 84;
    return 0;
}

/**
 * @brief Main ommand for sorting workshop items.
 *
 * Parses sorting criteria and applys the algorithm to the workshop list.
 *
 * @param data
 * @param token
 * @return int
 */
int sort(void *data, char **token)
{
    workshop_t *shop = (workshop_t *)data;
    sort_info_t infos[4];

    if (!token || !token[0])
        return 84;
    initialize_struct_infos(infos);
    if (parse_token(token, infos) == 84)
        return 84;
    quick_sort(shop->list_head, infos);
    return 0;
}
