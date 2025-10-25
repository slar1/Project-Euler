#include "../include/array_utils.h"
#include "../include/find_factors.h"
#include <stddef.h>
#include <stdio.h>

int element_exists(int element, int *arr, size_t length) {
  for (int i = 0; i < length; i++) {
    if (element == arr[i]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  // Find the sum of all positive integers that cannot be written as the sum of
  // two abundant numbers
  //
  // All numbers greater than 28123 can be written as the sum of two abundant
  // numbers
  //
  // An abundant number is one where the sum of it's proper divisors add to a
  // greater number than the number itself
  //
  // After looking online theres a thing called the compliment.
  // You choose a number n, and then subtract from that number one of the
  // abundant numbers. If the result is in the list of abundant numbers you can
  // stop and move on the the next n. If not, then n is not the sum of two
  // proper divisors.
  //
  // Step 1: Calculate all abundant numbers up to 28123
  int limit = 28123;

  int abundant_numbers[limit];
  int non_abundant_sum = 0;

  int abundant_count = 0;

  for (int i = 1; i < limit; i++) {
    unsigned long *proper_divisors =
        find_proper_divisors_simple((unsigned long)i);
    int length = count_array_elements(proper_divisors);
    int sum = 0;
    for (int j = 0; j < length; j++) {
      sum += proper_divisors[j];
    }
    if (sum > i) {
      abundant_numbers[abundant_count++] = i;
    }
  }

  // Step 2: for each integer up to 28123, if that integer is greater than any
  // abundant numbers, then subtract that abundant number from the integer and
  // see if the compliment exists in the abundant numbers.
  int broke;
  for (int i = 1; i <= limit; i++) {
    broke = 0;

    for (int j = 0; j < abundant_count; j++) {
      if (abundant_numbers[j] >= i) {
        break;
      }
      int compliment = i - abundant_numbers[j];
      if (element_exists(compliment, abundant_numbers, abundant_count)) {
        broke = 1;
        break;
      }
    }
    if (!broke) {
      non_abundant_sum += i;
    }
  }
  printf("%d\n", non_abundant_sum);
  return 0;
}
