#include "find_primes.h"
#include <stdio.h>

int main() {
  unsigned long sum = 0;
  int count = 0;
  int target = 2000000;
  int reached_target = 0;
  unsigned long *prime_list = find_primes(target);

  while (!reached_target) {
    sum += prime_list[count];
    count += 1;
    if (prime_list[count] >= target) {
      reached_target = 1;
      printf("%lu\n", sum);
    }
  }
}
