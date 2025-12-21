#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

/**
 * @file array_utils.h
 * @brief Function declarations for type-agnostic arrays
 */

/**
 * @brief Error codes
 */
typedef enum {
  ARRAY_OK = -1,
  ARRAY_ERR_NULL = -2,
  ARRAY_ERR_OOB = -3,
  ARRAY_ERR_ALLOC = -4,
  ARRAY_ERR_EMPTY = -5
} ArrayError;

/**
 * @brief Type definition for print function pointer.
 */
typedef void (*PrintFunction)(void *);
typedef int (*CompareFunction)(void *, void *);

typedef struct __array_t {
  void *arrayPtr;
  int size;
  int length;
  int elementSize;
  // PrintFunction print;
  // PrintFunction compare;
} Array;

/**
 * @brief Creates a new Array type.
 * @param Pointer to array struct, size of array, length of array (number of
 * array elements), size of each element, pointer to print function to be used.
 * @return Array array (Array struct).
 */

Array createArray(void *arrayPtr, int size, int length, int elementSize,
                  PrintFunction print, CompareFunction compare);
/**
 * @brief Prints each element of array.
 * @param Pointer to Array type
 */
int printArray(Array *array, PrintFunction print);

/**
 * @brief Compares two array values.
 * @param Pointer to Array type, pointer to compare function.
 */
int compareValues(Array *array, CompareFunction compare, void *value);

/**
 * @brief Functions for printing various types.
 */
#include <stdio.h>
void printInt(void *value);
void printFloat(void *value);
void printDouble(void *value);
// void printString(void *value);

/**
 * @brief Checks if array is full. If full resizes to double original size.
 * @param Pointer to Array type.
 */
int resizeArray(Array *array);

/**
 * @brief Appends element to end of array.
 * @param Pointer to Array type, value to be appended.
 */
int appendArray(Array *array, void *value);

/**
 * @brief Starting at given index, array elements including the element at the
 * given index are shifted to the right according to the value indicated by
 * shiftValue.
 * @param Pointer to Array type, index where shift takes place, number of
 * spaces to be shifted.
 */
// int shiftArray(Array *array, int index, int shiftValue);

/**
 * @brief Inserts value at specified index in array.
 * @param Pointer to Array, value to be inserted.
 */
int insertValue(Array *array, int index, void *value);

/**
 * @brief Deletes value at specified index.
 * @param Pointer to Array, index to be deleted.
 */
int deleteIndex(Array *array, int index);

/**
 * @brief Searches array for specified value.
 * @param Pointer to Array, value to search for.
 * @return Index for that value.
 */
int searchArray(Array *array, CompareFunction compare, void *value);

// void* getValue(Array array, int index);
//
// void setIndex(Array array, int index, void *value);
//
// void maxValue(Array array);
//
// void minValue(Array array);
//
// void reverseArray(Array array);

#endif
