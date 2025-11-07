#include <gmp.h>
#include <stdio.h>

// I think I'll stick with long double since it has about 20 digits of precision
// 1/10^1 will have 0.0###...
// 1/10^2 will have 0.00##...
// 1/10^3 will have 0.000#...
//
// Make a

int main() {
  for (long double i = 2; i < 1002; i++) {
    long double d = (long double)1 / i;
    printf("%d: %.20Lf\n", (int)(i - 1), d);
  }
  return 0;
}
