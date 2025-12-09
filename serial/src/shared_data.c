// Copyright 2025 Alejandro Guerra <alejandro.guerrarodriguez@ucr.ac.cr> CC-BY-4

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

# include "../include/shared_data.h"

// Creates the shared_data struct
shared_data_t* shared_data_create(int error) {
  shared_data_t* s = malloc(sizeof(shared_data_t));
  if (!s) {
    error = ENOMEM;
  }
  return s;
}
