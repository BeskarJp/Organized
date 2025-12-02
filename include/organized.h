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

typedef struct s_sort_tag {
    int (*cmp)(hardware_t *, hardware_t *, int);
    int reverse;
} sort_tag_t;

int compare_name(hardware_t *a, hardware_t *b, int reverse);
int compare_type(hardware_t *a, hardware_t *b, int reverse);
int compare_id(hardware_t *a, hardware_t *b, int reverse);

#endif /* ORGANIZED */
