#include "../include/array_utils.h"
#include <math.h>
#include <stdio.h>

int is_pandigital(double multiplicand, double multiplier) {
  double product = multiplicand * multiplier;
  double check[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  double numbers[] = {multiplicand, multiplier, product};
  int found[9] = {0};

  for (int i = 0; i < 3; i++) {
    double temp_num = (int)numbers[i];
    while (temp_num != 0) {
      int digit = (int)temp_num % 10;
      temp_num = floor(temp_num / 10);
      if (found[digit - 1] == digit) {
        return 0;
      } else {
        found[digit - 1] = digit;
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    if (found[i] != check[i]) {
      return 0;
    }
  }

  // printf("multiplicand: %f\nmultiplier: %f\nproduct: %f\n\n", multiplicand,
  //        multiplier, product);
  return (int)product;
}

int main() {
  int sum = 0;
  int products[10] = {0};
  int product_index = 0;
  for (double i = 1; i < 10000; i++) {
    for (double j = i + 1; j < 10000; j++) {
      int repeat = 0;
      int pan_num = is_pandigital(i, j);
      if (pan_num) {
        for (int k = 0; k <= product_index; k++) {
          if (pan_num == products[k]) {
            repeat = 1;
            break;
          }
        }
        if (repeat != 1) {
          products[product_index] = pan_num;
          product_index++;
        }
      }
    }
  }

  for (int i = 0; i < product_index; i++) {
    // printf("%d ", products[i]);
    sum += products[i];
  }
  printf("%d\n", sum);
  return 0;
}
