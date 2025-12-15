#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

/**
 * @file array_utils.h
 * @brief Function declarations for type agnostic arrays
 */

typedef struct __array_t {
  void *arr;
  int size;
  int length;
} Array;

/**
 * @brief Counts the number of elements of an unsigned long array
 * @param Pointer to array
 * @return Returns integer number of elements
 */
int count_array_elements(unsigned long *prime_array);

#endif
