#pragma once

#define MESSAGE 1
#define SIZE 40

typedef char msg[SIZE];
typedef struct {
    long type;
    msg mess;
} messagebuf;

void producer(int queue, char* m);
void consumer(int queue);
void msginfo(int queue);
