#ifndef _PROCEDURE_H
#define _PROCEDURE_H

#include <unistd.h>
#include <stdio.h>
#include "../header/monitor_signal_continue.h"

enum varconds{VAR_COND_READER, VAR_COND_WRITER};

typedef int T;

typedef struct reader_writer{
    T buffer;

    int nreaders;
    int nwriters;

    Monitor monitor;
}Buffer;

void startr(Buffer*);
T	 read(Buffer*);
void endr(Buffer*);
void startw(Buffer*);
void write(Buffer*, T value);
void endw(Buffer*);

#endif