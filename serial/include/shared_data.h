// Copyright 2025 Alejandro Guerra <alejandro.guerrarodriguez@ucr.ac.cr> CC-BY-4
#ifndef SHARED_DATA
#define SHARED_DATA


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct shared_data {
  char* work_directory;
  char* work_file;
  char* output_directory;
  size_t thread_count;
} shared_data_t;

shared_data_t* shared_data_create(int&);

#endif  // SHARED_DATA
