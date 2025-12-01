/*
** EPITECH PROJECT, 2025
** organized.h
** File description:
** Include of project
*/

#ifndef ORGANIZED
    #define ORGANIZED

typedef struct s_hardware {
    char *type;
    char *name;
    int id;
} hardware_t;

typedef struct s_linked_list {
    void *data;
    struct s_linked_list *next;
} linked_list_t;

typedef struct s_workshop {
    linked_list_t *list_head;
    int next_id;
} workshop_t;

#endif /* ORGANIZED */
