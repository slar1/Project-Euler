#include "../include/find_factors.h"
#include "../include/find_primes.h"
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

unsigned long *find_factors_simple(unsigned long n) {
  unsigned long *factor_list;
  size_t size = 64;
  int index = 0;

  factor_list = (unsigned long *)malloc(size * sizeof(unsigned long));
  if (factor_list == NULL) {
    exit(1);
  }

  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      factor_list[index] = i;
      index += 1;

      unsigned long other = n / i;
      if (other != i) {
        factor_list[index] = other;
        index += 1;
      }
    }

    if (index >= (int)size - 2) {
      size *= 2;
      factor_list = realloc(factor_list, size * sizeof(unsigned long));
      if (!factor_list)
        exit(1);
    }
  }

  factor_list[index] = 0;

  return factor_list;
}

// unsigned long *find_prime_factors_simple(unsigned long n) {
//
//   unsigned long *factor_list = find_factors_simple(n);
//   unsigned long *prime_list;
//
//   for (int i = 0; factor_list[i] != 0; i++) {
//     if (isPrime(factor_list[i])) {
//
//
//
//     }
//
//   }
//   return prime_list;
// }

unsigned long *find_proper_divisors_simple(unsigned long n) {
  unsigned long *factor_list;
  size_t size = 64;
  int index = 0;

  factor_list = (unsigned long *)malloc(size * sizeof(unsigned long));
  if (factor_list == NULL) {
    exit(1);
  }

  for (int i = 1; i <= (unsigned long)sqrt(n); i++) {
    if (n % i == 0) {
      if (i != n) {
        factor_list[index++] = i;
      }

      unsigned long other = n / i;
      if (other != i && other != n) {
        factor_list[index++] = other;
      }
    }

    if (index >= (int)size - 2) {
      size *= 2;
      factor_list = realloc(factor_list, size * sizeof(unsigned long));
      if (!factor_list)
        exit(1);
    }
  }

  factor_list[index] = 0;

  return factor_list;
}

int gcd(int a, int b) {
  int c;
  if (a > b) {
    c = a;
    a = b;
    b = c;
  }

  for (int i = a; a != 0; a--) {
    if (a % i == 0) {
      if (b % i == 0) {
        return i;
      }
    }
  }
  return -1;
}
