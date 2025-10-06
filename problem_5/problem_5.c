#include <stdio.h>
#include <time.h>

int main() {
  /*
    What is the smallest positive number that is evenly divisible by all of the
    numbers from 1 to 20? The number must be divisible by 20, so I can loop up
    by 20 each time and keep checking if it's divisible by the other numbers
  */

  // for checking execution time
  clock_t start, end;
  double cpu_time;
  start = clock();

  int n = 20;
  int found = 0;

  while (!found) {
    for (int i = 2; i <= 20; i++) {
      if (n % i != 0) {
        n += 20;
        // printf("%d\n", n);
        break;
      } else if (i == 20) {
        found = 1;
        printf("Found: %d\n", n);
      }
    }
  }

  end = clock();
  cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Execution time: %f seconds\n", cpu_time);

  return 0;
}
