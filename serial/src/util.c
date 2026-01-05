// Copyright 2025 Alejandro Guerra <alejandro.guerrarodriguez@ucr.ac.cr> CC-BY-4
#include "../include/util.h"

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void print_error(const char* function_name, int error_code) {
  if (error_code == 0) {
      return; // no error
  }

  fprintf(stderr, "%s: %s (%d)\n",
          function_name,
          strerror(error_code),  // converts errno code to human-readable text
          error_code);
}


char* build_path(char* prefix, char* sufix) {
  // +2 for '/' and the null terminator
  size_t buffer_size = strlen(prefix) + strlen(sufix) + 2;

  char* path = calloc(buffer_size, sizeof(char));

  if (!path) {
    return NULL;
  }

  // Stores <prefix> + '/' + <sufix> + '\0' in path
  snprintf(path, buffer_size, "%s/%s", prefix, sufix);

  return path;
}
