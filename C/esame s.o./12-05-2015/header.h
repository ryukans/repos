#pragma once

#include <pthread.h>

#define BUFF_SIZE 3

enum status_flags{
    FREE,
    IN_USE,
    OCCUPIED
};

typedef struct {
    int id;
    int quote;

} Flight;

typedef struct flight_buffer {
    Flight flights[BUFF_SIZE];
    int status[BUFF_SIZE];
} Buffer;

void ins_flight(Buffer*, int id);
void rem_flight(Buffer*, int id);
void upd_flight(Buffer*, int id, int quote);
