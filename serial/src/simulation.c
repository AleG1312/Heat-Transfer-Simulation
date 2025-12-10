#include "../include/simulation.h"

#include <errno.h>
#include <stdio.h>
#include <unistd.h>  // To work with sysconf

#include "../include/shared_data.h"

int run_simulation(int argc, char* argv[]) {
  int error = 0;

  shared_data_t* shared_data = malloc(sizeof(shared_data_t));

  if (!shared_data) {
    fprintf(stderr, "shared_data_create: memory allocation failed (ENOMEM)\n");
    return error;
  }

  int error = analyze_arguments(argc, argv, shared_data);

  if (error == EIO) {
    fprintf(stderr, "usage: make run ARGS=\"<work directory> <work file> "\
        "<output directory> <thread count>\"\n");
    return error;
  }

}

int analyze_arguments(int argc, char* argv[], shared_data_t* shared_data) {
  int error = 0;
  if (argc < 4 || 5 < argc) {
    return EIO;
  }

  shared_data->work_directory = argv[1];
  shared_data->work_file = argv[2];
  shared_data->output_directory = argv[3];
  shared_data->thread_count = sysconf(_SC_NPROCESSORS_ONLN);

  if (argc == 5) {
    if (sscanf(argv[4], "%d", &shared_data->thread_count) != 1) {
      return EIO;
    }
  }

  return error;
}
