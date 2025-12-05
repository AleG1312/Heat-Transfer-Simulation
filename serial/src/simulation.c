#include "../include/simulation.h"


int run_simulation(int argc, char* argv[]) {
  int error = analyze_arguments(argc, argv);

  if (error) {
    return error;
  }
  
}

int analyze_arguments(int argc, char* argv[]);
