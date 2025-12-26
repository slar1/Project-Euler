#include <math.h>
#include <stdio.h>

int main() {
  int sum_total = 0;
  int theoretical_maximum = pow(9, 5) * 6;
  for (int i = 0; i <= theoretical_maximum; i++) {
    // https://www.geeksforgeeks.org/c/how-to-convert-an-integer-to-a-string-in-c/
    int temp = i;
    int sum = 0;

    while (temp > 0) {
      int digit = temp % 10;
      sum += pow(digit, 5);
      temp /= 10;
    }

    if (sum == i) {
      if (sum == 0 || sum == 1) {
        continue;
      }
      printf("i: %d\nsum: %d\n\n", i, sum);
      sum_total += sum;
    }
  }
  printf("sum_total: %d\n", sum_total);
  return 0;
}
