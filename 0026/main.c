#include <gmp.h>
#include <mpfr.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *getUnitFractionMantissa(long double i, size_t digits) {
  mpfr_t n, d, result;
  mp_exp_t exp;
  char *mantissa;
  int bits = 1028 * 2000;
  // size_t digits = 50;

  mpfr_init2(n, bits);
  mpfr_init2(d, bits);
  mpfr_init2(result, bits);

  mpfr_set_ld(n, 1, MPFR_RNDN);
  mpfr_set_ld(d, i, MPFR_RNDN);
  mpfr_set_ld(result, 1, MPFR_RNDN);

  mpfr_div(result, n, d, MPFR_RNDN);

  mantissa = mpfr_get_str(NULL, &exp, 10, digits, result, MPFR_RNDD);

  char *out = malloc(digits * 100);
  strcpy(out, mantissa);
  return out;
}

int sequenceLength(const char *str, int str_length) {
  // Check each index in blocks the same size as the sequence length,
  // comparing block1 with block2. Where block1 starts at i and
  // ends at i + sequence_length - 1. block2 starts at i + sequence_length
  // and ends at i + sequence_length * 2 - 1. Successive blocks are then
  // overlapped. For example, block3 would coincide with block2, and block4
  // would start after block3.
  // To prevent smaller sequences from signalling too many positive comparisons
  // a fail variable is used. The number of reps is compared to the fail
  // variable and if it's greater, then the sequence_length is returned.

  // Check each possible sequence length.
  for (int sequence_length = 1; sequence_length <= str_length / 2;
       sequence_length++) {
    int reps = 0;
    int fails = 0;
    int first_pos = 0;
    int second_pos = first_pos + sequence_length;

    char first_string[str_length / 2 + 1];
    char second_string[str_length / 2 + 1];

    strncpy(first_string, str + first_pos, sequence_length);
    strncpy(second_string, str + second_pos, sequence_length);

    for (int i = 0; i < (str_length - sequence_length * 2);
         i += sequence_length) {

      first_string[sequence_length] = '\0';
      second_string[sequence_length] = '\0';

      if (strcmp(first_string, second_string) == 0) {
        reps++;
      } else {
        fails++;
      }
      if (fails > 10) {
        break;
      }
    }
    if (reps > fails) {
      return sequence_length;
    }
  }
  return 0;
}

int main() {
  // clock_t start, end;
  // start = clock();

  int ultimate_d = 0;
  int ultimate_sequence_length = 0;

  int length = 2000;

  for (long double d = 1; d < 1001; d++) {
    const char *str = getUnitFractionMantissa(d, length);
    int sequence_length = sequenceLength(str, length);
    if (sequence_length > ultimate_sequence_length) {
      ultimate_d = d;
      ultimate_sequence_length = sequence_length;
    }
  }
  printf("Mantissa: %s\nd: %d, mag: %d\n",
         getUnitFractionMantissa(ultimate_d, length), ultimate_d,
         ultimate_sequence_length);
  // end = clock();
  // double time = ((double)end - start) / CLOCKS_PER_SEC;
  // printf("Time: %f", time);
  return 0;
}
