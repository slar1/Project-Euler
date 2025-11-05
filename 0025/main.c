#include <assert.h>
#include <stdio.h>
// https://gmplib.org/gmp-man-6.3.0.pdf
// https://machinecognitis.github.io/Math.Gmp.Native/html/71884691-07d0-7bdf-c761-df9b07723735.htm
// It might be better to just use gmp directly instead of creating
// my own functions with it in my src directory. I think if I find
// myself doing a particular calculation I'll just add it to src/.
#include <gmp.h>

int main() {
  // What is the index of the first term in the fibonacci sequence
  // to have 1000 digits

  // Create integer 10^1000
  mpz_t thousand_digits;
  mpz_init(thousand_digits);

  char thousand_digit_string[1001];
  thousand_digit_string[0] = '1';

  for (int i = 1; i < 1000; i++) {
    thousand_digit_string[i] = '0';
  }
  thousand_digit_string[1000] = '\0';

  mpz_set_str(thousand_digits, thousand_digit_string, 10);

  // Calculate Fibonacci until it's >= than the thousand_digits
  // Return the index of that number
  int found = 0;
  unsigned long n = 1;
  mpz_t fn;
  mpz_init(fn);

  while (!found) {
    mpz_fib_ui(fn, n);
    if (mpz_cmp(fn, thousand_digits) >= 0) {
      printf("Index: %lu\n", n);
      found = 1;
    }
    n += 1;
  }

  mpz_clear(thousand_digits);
  mpz_clear(fn);

  return 0;
}
