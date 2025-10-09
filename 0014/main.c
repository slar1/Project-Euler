#include <stdio.h>

int main() {
  int longest_chain = 0;
  int number = 0;

  for (int i = 1; i <= 1000000; i++) {
    int count = 0;
    unsigned long n = i;
    while (n != 1) {
      if (n % 2 == 0) {
        n = n / 2;
        count += 1;
      } else {
        n = 3 * n + 1;
        count += 1;
      }
    }
    if (count > longest_chain) {
      longest_chain = count;
      number = i;
    }
  }
  printf("%d\n", number);
  return 0;
}
