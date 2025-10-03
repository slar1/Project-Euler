#include <math.h>
#include <stdio.h>

int main() {
  unsigned long sum = 0;

  for (int i = 1; i <= 633000; i++) {
    unsigned long square = pow(i, 2);

    if (square % 2 != 0) {
      sum += square;
    };
  };
  printf("Sum of odd squares: %lu\n", sum);
  return 0;
}
