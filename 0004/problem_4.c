#include <stdio.h>
#include <string.h>

int is_palindrome(int n) {
  /*
   * Checks to see if an integer is a palindrome
   * Parameter: integer value n
   * Returns 1 if palindrome exists or 0 if no palindrome exists
   */
  char n_string[15];
  sprintf(n_string, "%d", n);

  int palindrome = 1;

  for (int i = 0; i < strlen(n_string); i++) {
    char mirror = n_string[i];
    char image = n_string[strlen(n_string) - 1 - i];

    if (mirror == image) {
      continue;
    } else {
      palindrome = 0;
      break;
    }
  }
  return palindrome;
}

int main() {
  int limit = 999;
  int largest_palindrome;
  int test;

  for (int i = 0; i < limit; i++) {
    for (int j = 0; j < limit; j++) {
      test = i * j;
      if (is_palindrome(test) && test > largest_palindrome) {
        largest_palindrome = test;
      }
    }
  }
  printf("%d\n", largest_palindrome);
  return 0;
}
