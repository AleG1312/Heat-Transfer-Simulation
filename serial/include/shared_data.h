// Copyright 2025 Alejandro Guerra <alejandro.guerrarodriguez@ucr.ac.cr> CC-BY-4
#ifndef SHARED_DATA
#define SHARED_DATA


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct shared_data {
  // CLI parameters
  char* work_directory;
  char* work_file;
  char* output_directory;
  // Build later
  char* work_file_path;
  char* report_file_path;
} shared_data_t;

#endif  // SHARED_DATA
