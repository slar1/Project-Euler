#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_names(const void *name_1, const void *name_2) {
  //
  const char *name1 = *(const char **)name_1;
  const char *name2 = *(const char **)name_2;
  return strcmp(name1, name2);
}

int main() {
  FILE *fp = fopen("0022_names.txt", "r");
  if (!fp) {
    return 1;
  }

  // the f functions let you move around in a file
  // find how long the file is with fseek
  fseek(fp, 0, SEEK_END);
  // ftell returns the current position in bytes from the start of the file
  long size = ftell(fp);
  rewind(fp); // resets file position indicator to the beginning

  char *buffer = malloc(size + 1);
  size_t bytes_read = fread(buffer, 1, size, fp);

  if (bytes_read != size) {
    return 2;
  }
  buffer[size] = '\0';
  fclose(fp);

  char *names[6000]; // names is a list where each element is a pointer to a
                     // char and each char points to a string
  int count = 0;

  // breaks string into tokens seperated by delimiters
  char *token = strtok(buffer, ",");

  while (token != NULL) {
    if (token[0] == '"') {
      token++;
    }
    token[strlen(token) - 1] = '\0';
    names[count++] = token;
    token = strtok(NULL, ",");
  }

  // c standard library's quick sort
  // qsort expects
  qsort(names, count, sizeof(char *), compare_names);

  long long sum = 0;

  for (int i = 0; i < count; i++) {
    int letter_sum = 0;
    for (int j = 0; names[i][j] != '\0'; j++) {
      letter_sum += toupper(names[i][j]) - 'A' +
                    1; // characters are stored as ascii numbers
    }
    sum += (long long)letter_sum * (i + 1);
  }

  printf("%llu\n", sum);

  return 0;
}
