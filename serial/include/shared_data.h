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
  
  // Work file content
  char* plate_file;
  char* plate_file_path;
  size_t time_step;
  double thermal_diffusivity;
  size_t dimensions;
  double thermal_sensitivity;
  size_t states_count;
  double equation_factor;
} shared_data_t;

#endif  // SHARED_DATA
