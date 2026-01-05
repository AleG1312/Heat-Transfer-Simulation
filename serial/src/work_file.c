#include "../include/work_file.h"

#include <errno.h>
#include <stdio.h>

#include "../include/plate_file.h"
#include "../include/shared_data.h"

int process_work_file (shared_data_t* shared_data) {
  int error = 0;

  // Open work and report files
  FILE* w_file = fopen(shared_data->work_file_path, "r");
  FILE* r_file = fopen(shared_data->report_file_path, "w");

  if (!w_file || !r_file) {
    fprintf(stderr, "shared_data_create: memory allocation failed\n");
    fprintf(stderr, "process_work_file: opening files failed\n");
    return EIO;
  }

  char buffer[256];

  // Read every line in the work file
  while (fgets(buffer, 256, w_file)) {
    // Process the plate file
    error = process_plate_file(shared_data, buffer);

    // TODO(you):Add to the general report
  }

  return error;
}
