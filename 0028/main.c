#include <stdio.h>

int main() {
  int sum = 1;
  int square = 1001;
  int going_to_layer = (square + 1) / 2;
  int current_number = 1;
  for (int n = 2; n <= 501; n++) {
    int layer_number = 2 * n - 2;
    for (int i = 1; i <= 4; i++) {
      current_number += layer_number;
      sum += current_number;
    }
  }
  printf("%d\n", sum);
  return 0;
}
