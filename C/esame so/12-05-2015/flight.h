#pragma once

#include "monitor.h"

#define BUF_SIZE 3

enum status_flags{
    FREE,
    IN_USE,
    OCCUPIED
};


typedef struct message{
    int id;
    int quote;

} Flight;

typedef struct message_buffer {
    Flight flights[BUF_SIZE];
    int status[BUF_SIZE];
    
    int nfree;
    //int noccup;

    monitor m;
} Buffer;


void init_buffer(Buffer*);
void destroy_buffer(Buffer*);

void ins_flight(Buffer*, int id);
void rem_flight(Buffer*, int id);
void upd_flight(Buffer*, int id, int quote);
