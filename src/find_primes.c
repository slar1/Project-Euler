#include "../include/find_primes.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long *find_primes(unsigned long n) {
  unsigned long *prime_list_temp = malloc(sizeof(unsigned long) * n);
  memset(prime_list_temp, 1, sizeof(unsigned long) * n);

  int k = 0;
  unsigned long *prime_list = malloc(sizeof(unsigned long) * n);

  if (!prime_list || !prime_list_temp) {
    exit(1);
  }
  prime_list_temp[0] = prime_list_temp[1] = 0;

  for (unsigned long i = 2; i < n; i++) {
    if (prime_list_temp[i]) {
      for (unsigned long j = i * i; j < n; j += i) {
        prime_list_temp[j] = 0;
      }
    }
  }

  for (int i = 2; i < n; i++) {
    if (prime_list_temp[i]) {
      prime_list[k] = i;
      k += 1;
    }
  }
  free(prime_list_temp);
  prime_list[k] = 0;
  return prime_list;
}

int isPrime(int n) {
  if (n < 2) {
    return 0;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  printf("Prime: %d\n", n);
  return 1;
}
