#include "find_primes.h"
#include <math.h>
#include <stdio.h>

int prime_count(unsigned long *prime_array) {
  size_t count = 0;
  while (prime_array[count] != 0) {
    count++;
  }
  return count;
}

int main() {
  int number_of_primes = 0;
  unsigned long n = (unsigned long)round(10001 * log(10001));
  int target = 10001;
  unsigned long *prime_list = find_primes(n);

  while (prime_count(prime_list) < target) {
    n = n * 2;
    prime_list = find_primes(n);
    if (prime_count(prime_list) > target) {
      unsigned long nth_prime = prime_list[target - 1];
      printf("%lu\n", nth_prime);
    }
  }
}
