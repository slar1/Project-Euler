#include "../include/find_factors.h"
#include <math.h>
#include <stdio.h>

// There are 4 non-trivial examples of a fraction containing common digits in
// the numerator and denominator where you can "cancel out" the common digit
// and yet still obtain the correct fraction. For example the 9's in 49 / 98
// can be cancelled out to obtain 4 / 8, which still represents the original
// fraction.
// There are four non-trivial examples of this where the fraction is less than
// 1 and contains two digits in the numerator and denominator.
// Find them, in their lowest common term, then multiply their denominators
//
// I'm working with digits from 1 - 99. Easy.
// The fraction always produces a value less than 1. So first loop starting at
// 11, second loop starting at 11 + 1? I guess 11 / 11 is considered trivial
// also.

int compare_floats(float a, float b) {
  float epsilon = 0.00001f;
  // fabs returns absolute value of floating point number.
  // Check if the difference between a and b is less than 0.00001
  return fabs(a - b) < epsilon;
}

int main() {
  int product_num = 1;
  int product_den = 1;
  for (int a = 11; a < 100; a++) {
    for (int b = a + 1; b < 100; b++) {
      int n1 = (int)(a / 10) % 10;
      int n2 = a % 10;
      int d1 = (int)(b / 10) % 10;
      int d2 = b % 10;

      float original_fraction = (float)a / (float)b;

      if (n2 == 0 || d2 == 0) {
        continue;
      }

      if (a == b) {
        continue;
        ;
      }
      // printf("a / b: %d / %d\n\n", a, b);

      if (n1 == d2) {
        float new_fraction = (float)n2 / (float)d1;
        if (compare_floats(new_fraction, original_fraction)) {
          // printf("a / b: %d / %d\n\n", a, b);
          // printf("n1 / d2: %d / %d\n\n", n1, d2);
          product_num *= a;
          product_den *= b;
        }
      }

      if (n2 == d1) {
        float new_fraction = (float)n1 / (float)d2;
        if (compare_floats(new_fraction, original_fraction)) {
          // printf("a / b: %d / %d\n\n", a, b);
          // printf("n2 / d1: %d / %d\n\n", n1, d2);
          product_num *= a;
          product_den *= b;
        }
      }
    }
  }

  // printf("final: %d / %d", product_num, product_den);
  printf("product: %d\n", product_den / gcd(product_num, product_den));
  return 0;
}
