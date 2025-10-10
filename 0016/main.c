#include <math.h>
#include <stdio.h>

int main() {
  char str[400];
  int i = 0;
  sprintf(str, "%f", pow(2, 1000));
  int sum = 0;

  while (str[i] != '.') {
    sum += str[i] - '0';
    i++;
  }

  printf("%d\n", sum);
  return 0;
}
