#include "../include/find_factors.h"
#include <stdio.h>

int main() {
  // from 1 to 10,000 evaluate each number's proper divisors and sum them
  // if the sum of that sum's proper divisors equals the original number
  // then they are amicable pairs

  int amacable_pair_sum = 0;

  for (int a = 2; a <= 10000; a++) {
    unsigned long *a_prop_div = find_factors_simple(a);
    int d_a = 0;

    for (int i = 0; a_prop_div[i] != 0; i++) {
      if (a_prop_div[i] != a) {
        d_a += a_prop_div[i];
      }
    }

    int b = d_a;

    unsigned long *b_prop_div = find_factors_simple(b);

    int d_b = 0;

    for (int j = 0; b_prop_div[j] != 0; j++) {
      if (b_prop_div[j] != b) {
        d_b += b_prop_div[j];
      }
    }

    if (a == d_b && b == d_a && a != b) {
      amacable_pair_sum += (a + b);
      // printf("a: %d\nb: %d\nd_a: %d\nd_b: %d\n", a, b, d_a, d_b);
    }
  }
  printf("%d\n", amacable_pair_sum / 2);

  return 0;
}
