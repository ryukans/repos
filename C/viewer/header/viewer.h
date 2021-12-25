#pragma once 

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define MAXSIZE 100
#define VIEWERPAHT "."
#define VIEWERID 'V'

enum exit_state{VIEWER_EXIT_SUCCESS, VIEWER_EXIT_FAILURE};

typedef char buffer_t[MAXSIZE];
typedef int qid_t;

typedef struct {
    long type;
    pid_t pid;
    buffer_t buffer;
} msg_t;

typedef struct {
    key_t key;
    qid_t id;
} ipc_t;

void recieve(qid_t src);