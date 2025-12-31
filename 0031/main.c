#include <stdio.h>
#include <time.h>

int main() {
  int combinations = 0;

  for (int a = 0; a <= 200; a += 200) {
    for (int b = 0; b <= 200; b += 100) {
      for (int c = 0; c <= 200; c += 50) {
        for (int d = 0; d <= 200; d += 20) {
          for (int e = 0; e <= 200; e += 10) {
            for (int f = 0; f <= 200; f += 5) {
              for (int g = 0; g <= 200; g += 2) {
                for (int h = 0; h <= 200; h += 1) {
                  if (a + b + c + d + e + f + g + h == 200) {
                    combinations++;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  printf("%d\n", combinations);
  return 0;
}
