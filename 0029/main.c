#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  mpz_t base;
  mpz_t exp;
  mpz_t result;
  mpz_init(base);
  mpz_init(exp);
  mpz_init(result);

  int found;
  char *unique_results[10000];

  int index = 0;

  for (unsigned long int a = 2; a <= 100; a++) {
    for (unsigned long int b = 2; b <= 100; b++) {
      printf("a: %lu\nb: %lu\n\n", a, b);
      mpz_ui_pow_ui(result, a, b);
      // mpz_get_str(buffer, 10, result); // This doesn't work because it uses
      // the same buffer address each time.

      char *string = mpz_get_str(NULL, 10, result);

      if (index == 0) {
        unique_results[index] = string;
        index++;
        continue;
      }
      found = 0;

      for (int i = 0; i < index; i++) {
        if (strcmp(string, unique_results[i]) == 0) {
          printf("result string: %s\nunique result: %s\n", string,
                 unique_results[i]);
          free(string);
          found = 1;
          break;
        }
      }
      if (!found) {
        unique_results[index++] = string;
      }
    }
  }

  printf("%d\n", index);

  return 0;
}
