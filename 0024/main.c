#include <stdio.h>

int main() {
  // What is the millionth lexographic permutation of the digits 0, 1, 2, 3, 4,
  // 5, 6, 7, 8, 9? I don't need to calculate all permutation, I just need to
  // make an algorithm that generates ordered permutations.
  //
  // https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order

  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int arr_len = 10;
  int perms = 2;
  int rank = 1000000 + 1;

  while (perms < rank) {
    // step 1 - find the largest index k such that arr[k] < arr[k + 1]
    int largest_index_k = -1;

    for (int i = arr_len - 2; i >= 0; i--) {
      if (arr[i] < arr[i + 1] && i > largest_index_k) {
        largest_index_k = i;
      }
    }

    if (largest_index_k == -1) {
      printf("All permutations found\n");
      return 0;
    }

    // step 2 - find the largest index i greater than k such that arr[k] <
    // arr[i]
    int largest_index_i = -1;
    for (int i = arr_len - 1; i >= 0; i--) {
      if (i > largest_index_i && i > largest_index_k &&
          arr[largest_index_k] < arr[i]) {
        largest_index_i = i;
      }
    }

    // step 3 - swap arr[k] and arr[i]
    int k_value = arr[largest_index_k];
    arr[largest_index_k] = arr[largest_index_i];
    arr[largest_index_i] = k_value;

    // step 4 - reverse sequence after k
    int temp;
    int count_down = arr_len - 1;

    for (int i = largest_index_k + 1; count_down - i >= 0; i++) {
      temp = arr[i];
      arr[i] = arr[count_down];
      arr[count_down] = temp;
      count_down -= 1;
    }

    if (perms == rank - 1) {
      printf("permutation: %d\n", perms);
      for (int i = 0; i < arr_len; i++) {
        printf("%d", arr[i]);
      }
      printf("\n");
    }

    perms++;
  }
  return 0;
}
