#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_int_palindrome(int n) {
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

int is_string_palindrome(char *bin_string) {
  /*
   * Checks to see if an binary string is a palindrome
   * Parameter: pointer to string
   * Returns 1 if palindrome exists or 0 if no palindrome exists
   */
  // char n_string[15];
  // sprintf(n_string, "%d", n);

  int palindrome = 1;

  for (int i = 0; i < strlen(bin_string); i++) {
    char mirror = bin_string[i];
    char image = bin_string[strlen(bin_string) - 1 - i];

    if (mirror == image) {
      continue;
    } else {
      palindrome = 0;
      break;
    }
  }
  return palindrome;
}

char *int_to_bin(int num) {
  char *bin = malloc(100 * sizeof(char));
  int index = 0;

  // int temp_num = 1;
  // int count = 0;

  int power = 1;

  while (power < num) {
    power = power * 2;
  }

  power = power / 2;

  int fits;

  while (power > 0) {
    fits = num / power;

    if (fits == 1) {
      bin[index] = '1';
      index++;
    } else {
      bin[index] = '0';
      index++;
    }

    num = num - fits * power;
    power = power / 2;
  }
  bin[index] = '\0';
  return bin;
}

int main() {
  int sum = 0;

  for (int number = 0; number < 1000000; number++) {
    char *bin = int_to_bin(number);
    int index = 0;

    int int_pal = is_int_palindrome(number);
    int str_pal = is_string_palindrome(bin);

    if (int_pal && str_pal) {
      if (bin[0] != '0') {
        sum += number;

        printf("number: %d\n", number);
        printf("Binary: ");

        while (bin[index] != '\0') {
          printf("%c", bin[index]);
          index++;
        }

        printf("\n");

        printf("int is palindrome: %d\n", int_pal);
        printf("string is palindrome: %d\n", str_pal);

        free(bin);

        printf("\n");
      }
    }
  }

  printf("sum: %d\n", sum);
  return 0;
}
