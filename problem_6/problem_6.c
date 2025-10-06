#include <math.h>
#include <stdio.h>

int main() {
  unsigned long sum_of_squares;
  unsigned long square_of_sum;
  unsigned long difference;

  for (unsigned long i = 1; i <= 100; i++) {
    sum_of_squares += pow(i, 2);
  }

  for (unsigned long i = 1; i <= 100; i++) {
    square_of_sum += i;
  }

  square_of_sum = pow(square_of_sum, 2);
  difference = square_of_sum - sum_of_squares;

  printf("%lu\n", sum_of_squares);
  printf("%lu\n", square_of_sum);
  printf("%lu\n", difference);
}
