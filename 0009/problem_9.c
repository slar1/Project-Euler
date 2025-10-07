#include <math.h>
#include <stdio.h>

int main() {
  // a pythagrean triplet is a < b < c
  // where a^2 + b^2 = c^2
  // find the pythagrean triplet where a + b + c = 1000
  // when you find it return it's product a * b * c
  //
  // first find the triplets
  // then find the one that sums to 1000
  // c <= 997. which means the highest c^2 can be is 997^2 (997^2 = 994099)
  // the highest b can be is 499 because c must be larger
  // the highest a can be is 332 because 333 + 334 + 335 = 1002

  for (double a = 1; a < 333; a++) {
    for (double b = a + 1; b < 500; b++) {
      double c = sqrt(pow(a, 2) + pow(b, 2));
      if (a + b + c == 1000) {
        // if it adds to 1000 c must be an integer.
        printf("a = %d, b = %d, c = %d\n", (int)a, (int)b, (int)c);
        printf("a * b * c = %d\n", (int)a * (int)b * (int)c);
      }
    }
  }
  return 0;
}
