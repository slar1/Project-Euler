#include "../include/math_utils.h"
#include <gmp.h>
#include <stdio.h>

// If i did this without gmp:
// https://nagekar.com/2015/01/handling-large-numbers-with-cc.html

int main() {
  mpz_t fact;
  mpz_init(fact);
  factorial_big(fact, 100);

  char *str = mpz_get_str(NULL, 10, fact);

  int sum = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    sum += str[i] - '0'; // - '0' converts char to int
  }

  // gmp_printf("%Zd\n", fact);
  printf("%d\n", sum);
}
