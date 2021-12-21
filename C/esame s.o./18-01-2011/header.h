#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define CLIENTS 8
#define BALANCERS 1
#define SERVERS 3
#define REQUESTS 15 /* total client message requests */
#define SENDRATE 1  /* seconds */
#define CLIENT_T 1
#define BALANCER_T 2
#define SERVER_T 3
#define CLIENT_C "[1;36m"
#define BALANCER_C "[1;33;46;1m"
#define SERVER_C "[1;32;1;40;1m"
#define RESET_C "[0m"
#define PID_C "[7m" 


#define MSGSZ(x) sizeof(x)-sizeof(long)

typedef int qid_t;    /* queue id type */

typedef struct message{
    long type;
    pid_t pid;
} msg_t;

void reqsnd(qid_t); 
void reqblnc(qid_t, qid_t[]);
void reqrcv(qid_t);
void loginfo(const char* format, const char* color);


/*
void loginfo(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    char color[11];

    color[0] = '\0';
    while(*format != '\0'){
        if(*format == '%'){
            ++format;
            if(*format == 'C'){
                strcat(color, va_arg(args, const char*));
            }
            else if(*format == 'd'){

            }
        }
        ++format;
    }

    //char color[11] = "\033[0;30m"
    printf("%s ");
}*/
