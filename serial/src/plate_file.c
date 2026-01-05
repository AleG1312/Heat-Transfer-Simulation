#include "../include/plate_file.h"

#include <errno.h>
#include <string.h>

#include "../include/util.h"

int process_plate_file (shared_data_t* shared_data, char* buffer) {
  int error = 0;
  
  error = read_line(shared_data, buffer);

  if (!error) {
    // heat simulation
    // generate plate report
  }

  return error;
}

int read_line(shared_data_t* shared_data, char* buffer) {
  int error = 0;
  // Save the plate file
  if (sscanf(strtok(buffer, " "), "%s", &shared_data->plate_file) != 1) {
    sprintf(stderr, "read_line: sscanf failed\n");
    return EIO;
  }
  // Compute the plate file path
  shared_data->plate_file_path
      = build_path(shared_data->work_directory, shared_data->plate_file);
  // Save the time step
  if (sscanf(strtok(NULL, " "), "%zu", &shared_data->time_step) != 1) {
    sprintf(stderr, "read_line: sscanf failed\n");
    return EIO;
  }
  // Save the thermal diffusivity
  if (sscanf(strtok(NULL, " "), "%lf", &shared_data->time_step) != 1) {
    sprintf(stderr, "read_line: sscanf failed\n");
    return EIO;
  }
  // Save the dimentions
  if (sscanf(strtok(NULL, " "), "%zu", &shared_data->dimensions) != 1) {
    sprintf(stderr, "read_line: sscanf failed\n");
    return EIO;
  }
  // Save the thermal sensitivity
  if (sscanf(strtok(NULL, " "), "%lf", &shared_data->thermal_sensitivity) != 1) {
    sprintf(stderr, "read_line: sscanf failed\n");
    return EIO;
  }
  // Compute the constant equation factor
  shared_data->equation_factor
      = (shared_data->thermal_diffusivity * shared_data->time_step)
          / (shared_data->dimensions*shared_data->dimensions);

  return error;
}
