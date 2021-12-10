#pragma once

int initsem();

void childproc(int *vector,
            int *buffer,
            int sem_id,
            int first_elem,
            int nelem);

void fatherproc(int *buffer,
           int sem_id);

#define NUM_PROCESSES 10
#define NUM_ELEMENTS 10000
