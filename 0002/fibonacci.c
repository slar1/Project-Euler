#include "fibonacci.h"
#include <stdio.h>

int fibonacci(int n) {
  int last = 1;
  int previous = 0;
  int i;

  for (i = 1; i < n; i++) {
    int next = previous + last;
    previous = last;
    last = next;
  }

  return last;
};
