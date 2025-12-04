/*
** EPITECH PROJECT, 2025
** organized.h
** File description:
** Include of project
*/

#ifndef ORGANIZED
    #define ORGANIZED

    #include <stdlib.h>

typedef enum type {
    ACTUATOR,
    DEVICE,
    PROCESSORS,
    SENSORS,
    WIRES
} type_t;

typedef enum s_sort_type {
    TYPE,
    NAME,
    ID,
    UNKNOWN
} sort_type_t;

typedef struct s_hardware {
    char *name;
    int id;
    type_t type;
} hardware_t;

typedef struct s_linked_list {
    void *data;
    struct s_linked_list *next;
} linked_list_t;

typedef struct s_workshop {
    linked_list_t *list_head;
    int next_id;
} workshop_t;

typedef struct s_sort_info {
    sort_type_t type;
    int is_reverse;
} sort_info_t;

void bubble_sort(linked_list_t *list, sort_info_t *infos);
void free_workshop_data(workshop_t *shop);

#endif /* ORGANIZED */
