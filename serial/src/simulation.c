#include "../include/simulation.h"

#include <errno.h>
#include <stdio.h>

#include "../include/shared_data.h"
#include "../include/util.h"

int run_simulation(int argc, char* argv[]) {
  int error = 0;

  shared_data_t* shared_data = malloc(sizeof(shared_data_t));

  if (!shared_data) {
    fprintf(stderr, "shared_data_create: memory allocation failed\n");
    return ENOMEM;
  }

  int error = analyze_arguments(argc, argv, shared_data);

  if (error) {
    fprintf(stderr, "usage: make run ARGS=\"<work directory> <work file> "\
        "<output directory>\"\n");
    return error;
  }

}

int analyze_arguments(int argc, char* argv[], shared_data_t* shared_data) {
  int error = 0;

  if (argc != 4) {
    return EIO;
  }

  shared_data->work_directory = argv[1];
  shared_data->work_file = argv[2];
  shared_data->output_directory = argv[3];

  shared_data->work_file_path = build_path(argv[1], argv[2]);
  shared_data->report_file_path = build_path(argv[3], argv[2]);

  if (!shared_data->work_file_path || !shared_data->report_file_path) {
    fprintf(stderr, "analyze_arguments: memory allocation failed\n");
    return ENOMEM;
  }

  return error;
}
