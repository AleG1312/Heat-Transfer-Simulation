// Copyright 2024,2025 ECCI-UCR CC-BY-4
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#include "matrix.h"

void** create_matrix(const size_t rows, const size_t cols,
    const size_t element_size) {
  void** matrix = calloc(rows, sizeof(void*));
  if (matrix) {
    for (size_t row = 0; row < rows; ++row) {
      if ((matrix[row] = calloc(cols, element_size)) == NULL) {
        destroy_matrix(matrix, rows);
        return NULL;
      }
    }
  }
  return matrix;
}

void destroy_matrix(void** matrix, const size_t rows) {
  if (matrix) {
    for (size_t row = 0; row < rows; ++row) {
      free(matrix[row]);
    }
    free(matrix);
  }
}

void print_matrix(double** matrix, const size_t rows, const size_t cols) {
  for (size_t i = 0; i < rows; ++i) {
    printf("[ ");
    for (size_t j = 0; j < cols; ++j) {
      printf("%12.8f ", matrix[i][j]);
    }
    printf("]\n");
  }
  printf("\n");
}

