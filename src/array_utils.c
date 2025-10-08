#include "../include/array_utils.h"
#include <stdlib.h>
#include <string.h>

int count_array_elements(unsigned long *array) {
  size_t count = 0;
  if (array == NULL) {
    exit(1);
  }
  while (array[count] != 0) {
    count++;
  }
  return count;
}
