// Copyright 2024,2025 ECCI-UCR CC-BY-4
#pragma once

#include <stddef.h>
#include <stdint.h>

void** create_matrix(const size_t rows, const size_t cols,
    const size_t element_size);

void destroy_matrix(void** matrix, const size_t rows);

void print_matrix(double** matrix, const size_t rows, const size_t cols);

#define CREATE_MATRIX(type, name, rows, cols)\
    type** name = (type**)create_matrix(rows, cols, sizeof(type))
