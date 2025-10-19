#include <stdio.h>
#include <stdlib.h>

#define ROWS 100

int main() {
  FILE *f = fopen("0067_triangle.txt", "r");

  char buffer[1024];
  int triangle[ROWS][ROWS] = {0};

  for (int i = 0; i < ROWS; i++) {
    char *ptr = buffer;

    if (!fgets(buffer, sizeof(buffer), f)) {
      fprintf(stderr, "Error: unexpected end of file at line %d\n", i + 1);
      break;
    }

    for (int j = 0; j <= i; j++) {
      triangle[i][j] = (int)strtol(ptr, &ptr, 10);
      // printf("%d\n", triangle[i][j]);
    }
  }

  fclose(f);

  for (int i = ROWS - 2; i >= 0; i--) {  // row
    for (int j = 0; j < ROWS - 2; j++) { // column
      int root = triangle[i][j];
      int left = triangle[i + 1][j];
      int right = triangle[i + 1][j + 1];
      int bigger_option = 0;

      if (left > right) {
        bigger_option = left;
      } else if (left < right) {
        bigger_option = right;
      } else {
        bigger_option = left;
      }
      triangle[i][j] = root + bigger_option;
    }
  }
  printf("%d\n", triangle[0][0]);
}
