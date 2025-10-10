// This also works. Someone posted it on Euler forum. At each iteration i is
// dividing so it's keeping the number small.

#include <stdio.h>

unsigned long long binomial(int n, int k) {
  if (k > n - k)
    k = n - k;

  unsigned long long result = 1;
  for (int i = 1; i <= k; i++) {
    result = result * (n - i + 1) / i;
  }
  return result;
}

int main() {
  int n = 40, k = 20;
  printf("C(%d, %d) = %llu\n", n, k, binomial(n, k));
  return 0;
}
