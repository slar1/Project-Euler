#include "array_utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Array createArray(void *arrayPtr, int size, int length, int elementSize,
                  PrintFunction print, CompareFunction compare) {
  Array array;
  array.arrayPtr = arrayPtr;
  array.size = size;
  array.length = length;
  array.elementSize = elementSize;
  // array.print = print;
  // array.compare = compare;
  return array;
}

int printArray(Array *array, PrintFunction print) {
  if (!array) {
    return ARRAY_ERR_NULL;
  }

  for (int i = 0; i < array->length; i++) {
    void *elementPtr = (char *)array->arrayPtr + i * array->elementSize;
    print(elementPtr);
    printf(" ");
  }
  printf("\n");
  return ARRAY_OK;
}

// Print functions for variaous types. Want to include more features like
// precision.
void printInt(void *value) { printf("%d", *(int *)value); }
void printFloat(void *value) { printf("%f", *(float *)value); }
void printDouble(void *value) { printf("%lf", *(double *)value); }
// void printString(void *value) { printf("%c", *(char *)value); }

int compareValues(Array *array, CompareFunction compare, void *value) {
  for (int i = 0; i < array->length; i++) {
    void *elementPtr = (char *)array->arrayPtr + i * array->elementSize;

    if (compare(elementPtr, value) == 0) {
      return i;
    }
  }
  return 0;
}

// Comparison functions for various types.
int compareInt(void *value1, void *value2) {
  if (*(int *)value1 == *(int *)value2) {
    return 0;
  } else if (*(int *)value1 < *(int *)value2) {
    return 1;
  }
  return -1;
}

int resizeArray(Array *array) {
  if (!array) {
    return ARRAY_ERR_NULL;
  }

  if (array->length == array->size) {
    if (array->size == 0) {
      array->size = 2;
    } else {
      array->size = array->size * 2;
    }

    void *newPtr = realloc(array->arrayPtr, array->size);

    if (!newPtr) {
      return ARRAY_ERR_NULL;
    }

    array->arrayPtr = newPtr;
  }
  return ARRAY_OK;
}

int appendArray(Array *array, void *value) {
  if (!value) {
    return ARRAY_ERR_NULL;
  }

  int error = resizeArray(array);

  if (error != 0) {
    return error;
  }

  void *destination =
      (char *)array->arrayPtr + array->length * array->elementSize;
  memcpy(destination, value, array->elementSize);

  array->length++;
  return ARRAY_OK;
}

int insertValue(Array *array, int index, void *value) {
  if (!value) {
    return ARRAY_ERR_NULL;
  }

  int error = resizeArray(array);

  if (error != 0) {
    return error;
  }

  // Shifts array to the right.
  for (int i = array->length; i > index; i--) {
    void *destPtr = (char *)array->arrayPtr + i * array->elementSize;
    void *srcPtr = (char *)array->arrayPtr + (i - 1) * array->elementSize;
    memcpy(destPtr, srcPtr, array->elementSize);
  }

  void *indexPtr = (char *)array->arrayPtr + index * array->elementSize;
  memcpy(indexPtr, value, array->elementSize);
  array->length++;

  return ARRAY_OK;
}

int deleteIndex(Array *array, int index) {
  if (!array) {
    return ARRAY_ERR_NULL;
  } else if (index < 0) {
    return ARRAY_ERR_OOB;
  }

  // Shifts array to the right.
  for (int i = index; i < array->length - 1; i++) {
    void *destPtr = (char *)array->arrayPtr + i * array->elementSize;
    void *srcPtr = (char *)array->arrayPtr + (i + 1) * array->elementSize;
    memcpy(destPtr, srcPtr, array->elementSize);
  }

  array->length--;

  return ARRAY_OK;
}

int searchArray(Array *array, CompareFunction compare, void *value) {
  for (int i = 0; i < array->length; i++) {
    if (compareValues(array, compare, value) == 0) {
      return i;
    }
  }
  return -1;
}
