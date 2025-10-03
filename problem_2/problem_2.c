#include "fibonacci.h"
#include <stdio.h>

int main() {
  int sum = 0;
  int under = 1;
  int i;

  for (i = 1; fibonacci(i) <= 4000000; i++) {
    if (fibonacci(i) % 2 == 0) {
      sum += fibonacci(i);
    }
  }
  printf("Sum of even fibonacci's: %d\n", sum);

  return 0;
}
