#include "find_primes.h"
#include <math.h>
#include <stdio.h>

int main() {
  unsigned long number = 600851475143;
  unsigned long root = sqrt(number);
  unsigned long sum = 0;
  unsigned long *primes = find_primes(root);

  if (!primes) {
    return 1;
  }

  for (int i = 0; primes[i] != 0; i++) {
    if (number % primes[i] == 0) {
      sum = primes[i];
    }
  }
  printf("%lu\n", sum);
};
