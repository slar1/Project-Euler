#include "../include/find_factors.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long euclidean_gcd(unsigned long a, unsigned long b) {
  while (b != 0) {
    unsigned long t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int is_perfect_square(unsigned long n) {
  if (n < 0) {
    return 0;
  }

  unsigned long root = round(sqrt(n));

  return root * root == n;
}

// p_q quadratic_sieve(unsigned long n) {
//   // TODO: THIS LATER MAYBE.
//   p_q result;
//   result.p = 0;
//   result.q = 0;
//   return result;
// }

p_q small_n_factors(unsigned long n) {
  double x = round(sqrt((double)n));
  int found = 0;
  p_q result;

  while (!found) {
    double y_2 = pow(x, 2) - n;

    if (is_perfect_square(y_2)) {
      found = 1;
      result.p = x;
      result.q = sqrt(y_2);
    } else {
      x += 1;
    }
  }

  return result;
}

// unsigned long *find_factors(unsigned long n) {
//   // TODO: THIS LATER;
//   unsigned long *factor_list = {0};
//   return factor_list;
// }

unsigned long *find_factors_simple(unsigned long n) {
  unsigned long *factor_list;
  size_t size = 1000;
  int index = 0;

  factor_list = (unsigned long *)malloc(size * sizeof(unsigned long));
  if (factor_list == NULL) {
    exit(1);
  }

  for (int i = 1; i < n / 2; i++) {
    if (n % i == 0) {
      factor_list[index] = i;
      index += 1;
    }
  }
  return factor_list;
}

// unsigned long *find_factors_qs(unsigned long n) {
//   // TODO: THIS LATER MAYBE.
//   // Find factors using a quadratic seive
//   // https://www.youtube.com/watch?v=5ekTew5Kj7w
//   //
//   https://medium.com/nerd-for-tech/heres-how-quadratic-sieve-factorization-works-1c878bc94f81
//   unsigned long *result = {0};
//   return result;
// }
