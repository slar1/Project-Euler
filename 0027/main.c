#include "../include/find_primes.h"
#include <stdio.h>

void updateArr(int *arr, int a, int b, int consecutivePrimes) {
  arr[0] = a;
  arr[1] = b;
  arr[2] = consecutivePrimes;
}

int quadraticEquation(int n, int a, int b) { return n * n + n * a + b; }

int getConsecutivePrimes(int a, int b) {
  int count = 0;
  int primeFound = 1;
  for (int n = 0; primeFound; n++) {
    if (isPrime(quadraticEquation(n, a, b))) {
      count++;
    } else {
      primeFound = 0;
    }
  }
  return count;
}

static int arr[3] = {0, 0, 0};

int main() {
  for (int a = -999; a < 1000; a++) {
    for (int b = -1000; b <= 1000; b++) {
      if (b > 1 && isPrime(b)) {
        int consecutivePrimes = getConsecutivePrimes(a, b);
        if (arr[2] < consecutivePrimes) {
          updateArr(arr, a, b, consecutivePrimes);
        }
      }
    }
  }

  printf("a: %d\nb: %d\ncount: %d\na * b: %d\n", arr[0], arr[1], arr[2],
         arr[0] * arr[1]);
  printf("\n");
  return 0;
}
