#include <math.h>
#include <stdio.h>

long arr2int(int arr[], int arr_len) {
  long num = 0;
  long place = 1;
  for (int i = arr_len - 1; i >= 0; i--) {
    num += place * arr[i];
    place *= 10;
  }
  return num;
}

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

  // int arr[] = {0, 1, 2, 3};
  // int arr_len = 4;
  // int perms = 2;
  // int rank = 25;

  long prev_num = arr2int(arr, arr_len);
  long current_num = 0;

  for (int i = 0; i < arr_len; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");

  while (perms < rank) {
    // step 1 - find the largest index k such that arr[k] < arr[k + 1]
    int largest_index_k = -1;

    for (int i = arr_len - 1; i >= 0; i--) {
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
      // printf("arr_len - i: %d\n", arr_len - i - 1);
      // printf("switched index %d with index %d\n", i, count_down);
      temp = arr[i]; // start here
      arr[i] = arr[count_down];
      arr[count_down] = temp;
      count_down -= 1;
    }

    current_num = arr2int(arr, arr_len);
    printf("Previous number: %ld\nCurrent number: %ld\n", prev_num,
           current_num);
    if (prev_num > current_num) {
      printf("Previous is smaller than current: False\n");
      return 1;
    } else {
      printf("Previous is smaller than current: True\n");
    }
    prev_num = current_num;
    printf("permutation: %d\n", perms);
    for (int i = 0; i < arr_len; i++) {
      printf("%d", arr[i]);
    }
    printf("\n");

    perms++;
  }
  return 0;
}
