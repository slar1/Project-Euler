#include "../include/array_utils.h"
#include "../include/find_factors.h"
#include <stdio.h>

int calc_tri_num(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int main() {
  // find triangle numbers by creating a sum that adds the natural numbers
  // then find the factors for those triangle numbers
  // the first with over 500 factors wins

  int found = 0;
  int n = 1;

  while (!found) {
    int tri_num = calc_tri_num(n);
    unsigned long *factors = find_factors_simple(tri_num);

    int factor_count = count_array_elements(factors);
    // printf("Triangle number: %d\n", tri_num);
    // printf("Number of factors: %d\n", factor_count);

    if (factor_count > 500) {
      printf("%d\n", factor_count);
      printf("Found: %d\n", tri_num);
      found = 1;
    } else {
      n++;
    }
  }
}
