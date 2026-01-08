#include "../include/math_utils.h"
#include <stdio.h>

int compare(int num) {
  char str[100];

  int index = 0;
  int sum = 0;

  sprintf(str, "%d", num);

  while (str[index] != '\0') {
    int digit = str[index] - '0';
    int fact;

    fact = factorial(digit);
    // printf("Factorial: %d\n", fact);
    sum += fact;
    index++;
  }

  if (sum == num && sum > 2) {

    printf("num and sum: %d\n", sum);
    return 1;
  }

  return 0;
}

int main() {
  int sum = 0;

  for (int i = 1; i < 100000; i++) {
    if (compare(i)) {
      sum += i;
    }
  }

  printf("SUM: %d\n", sum);
  return 0;
}
