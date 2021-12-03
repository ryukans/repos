#ifndef _PROCEDURE_H
#define _PROCEDURE_H

#include <unistd.h>
#include <stdio.h>
#include "../header/monitor_signal_continue.h"

enum varcond{
    VAR_COND_READER,
    VAR_COND_WRITER
};

typedef int T;
typedef struct reader_writer{
    T buffer;

    int nreader;
    int nwriter;

    Monitor monitor;
}Buffer;

int read(Buffer*);
void writer(Buffer*, T value);

#endif