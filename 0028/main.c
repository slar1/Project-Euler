#include <stdio.h>

int main() {
  int sum = 1;
  int going_to_layer = 3;
  int current_number = 1;
  for (int n = 2; n <= 501; n++) {
    int layer_number = 2 * n - 2;
    for (int i = 1; i <= 4; i++) {
      current_number += layer_number;
      sum += current_number;
    }
  }
  printf("%d\n", sum);
  // int sum1 = 1;
  // for (int n = 2; n < 4; n++) { // For each layer
  //   int num_2_add = 2 * n - 1;  // The number to add is the layer number - 1
  //   for (int i = 0; i < 4; i++) {
  //     add_num = num_2_add ;
  //     sum1 += num_2_add;
  //   }
  // }
  // printf("%d\n", sum1);
  return 0;
}
