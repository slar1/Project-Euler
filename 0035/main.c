#include "../include/find_primes.h"
#include <stdio.h>

int isCircularPrime(double num) {
  double double_num = num;
  int temp_num = num;
  char double_str[100];

  int digit_count = 0;

  while (temp_num > 0) {
    if (temp_num % 10 == 0 || temp_num % 2 == 0 || temp_num % 5 == 0) {
      return 0;
    }

    digit_count++;
    temp_num /= 10;
  }

  for (int i = 1; i <= digit_count; i++) {
    double_num *= 10;
  }

  double_num += num;

  sprintf(double_str, "%f", double_num);

  for (int a = 0; a < digit_count; a++) {
    int rotation = 0;
    // printf("loop number: %d\n", a);

    for (int i = a; i < a + digit_count; i++) {
      rotation += double_str[i] - '0';

      if (i < a + digit_count - 1) {
        rotation *= 10;
      }
    }

    if (!isPrime(rotation)) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int count = 2;
  int start = 2;
  int end = 1000000;

  for (double i = start; i < end; i++) {
    if (isCircularPrime(i)) {
      // printf("%f\n", i);
      count++;
    }
  }
  printf("\n%d\n", count);

  return 0;
}
