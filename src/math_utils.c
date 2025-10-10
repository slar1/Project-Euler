#include "../include/math_utils.h"
#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long binomial_coefficient(int n, int k) {
  if (n < k || k < 0) {
    perror("n less than k or k less than 0.");
    exit(1);
  }
  unsigned long long n_fac = factorial(n);
  unsigned long long k_fac = factorial(k);
  unsigned long long n_k_fac = factorial(n - k);

  unsigned long long coefficient = n_fac / (k_fac * n_k_fac);
  return coefficient;
}

void factorial_big(mpz_t result, int n) {
  /*
   * In order to do use this I need to use the gmp structs and also free it
   * after:
   * mpz_t fact;
   * mpz_init(fact);
   * factorial_big(fact, 100);
   *
   * gmp_printf("100! = %Zd\n", fact);
   * mpz_clear(fact);
   */
  mpz_set_ui(result, 1);
  for (int i = 2; i <= n; i++) {
    mpz_mul_ui(result, result, i);
  }
}

unsigned long long factorial(int n) {
  /*
   * For factorials resulting in less than around 20 digits
   */
  unsigned long long factorial = 1;

  for (int i = 1; i <= n; i++) {
    factorial *= (unsigned long long)i;
  }
  return factorial;
}
