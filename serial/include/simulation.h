#ifndef SIMULATION_H
#define SIMULATION_H

#include "../include/shared_data.h"

int run_simulation(int argc, char* argv[]);

int analyze_arguments(int argc, char* argv[], shared_data_t*);

#endif  // SIMULATION_H