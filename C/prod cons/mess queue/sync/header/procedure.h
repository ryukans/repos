#pragma once

enum {
    RTS = 1,
    OTS,
    MESSAGE
};

#define SIZE 40

typedef char msg[SIZE];

typedef struct {
    long type;
    msg mess;
} messagebuf;

void init_serviceq();
void remove_serviceq();
void syncsnd(messagebuf*, int queue);
void blockedrcv(messagebuf*, int queue, int typemessage);
void producer(int queue, char* txt);
void consumer(int queue);