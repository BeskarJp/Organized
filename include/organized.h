/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** Include of Lib
*/

#ifndef ORGANIZED
    #define ORGANIZED

typedef enum {
    ACTUATOR,
    DEVICE,
    PROCESSOR,
    SENSOR,
    WIRE,
    NB_TYPES
} hardware_type_t;

typedef struct hardware_s {
    int id;
    hardware_type_t type;
    char *name;
    struct hardware_s *next;
} hardware_t;

typedef struct workshop_s {
    hardware_t *list;
    int next_id;
} workshop_t;

#endif /* ORGANIZED */
