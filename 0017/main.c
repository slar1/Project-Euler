#include <stdio.h>

int count_letters(char *str) {
  int count = 0;
  for (int i = 0; str[i] != 0; i++) {
    if (str[i] == ' ' || str[i] == '-') {
      continue;
    }
    count++;
  }
  return count;
}

int main() {
  char *number_words[] = {
      "one",           "two",           "three",        "four",
      "five",          "six",           "seven",        "eight",
      "nine",          "ten",           "eleven",       "twelve",
      "thirteen",      "fourteen",      "fifteen",      "sixteen",
      "seventeen",     "eighteen",      "nineteen",     "twenty",
      "twenty-one",    "twenty-two",    "twenty-three", "twenty-four",
      "twenty-five",   "twenty-six",    "twenty-seven", "twenty-eight",
      "twenty-nine",   "thirty",        "thirty-one",   "thirty-two",
      "thirty-three",  "thirty-four",   "thirty-five",  "thirty-six",
      "thirty-seven",  "thirty-eight",  "thirty-nine",  "forty",
      "forty-one",     "forty-two",     "forty-three",  "forty-four",
      "forty-five",    "forty-six",     "forty-seven",  "forty-eight",
      "forty-nine",    "fifty",         "fifty-one",    "fifty-two",
      "fifty-three",   "fifty-four",    "fifty-five",   "fifty-six",
      "fifty-seven",   "fifty-eight",   "fifty-nine",   "sixty",
      "sixty-one",     "sixty-two",     "sixty-three",  "sixty-four",
      "sixty-five",    "sixty-six",     "sixty-seven",  "sixty-eight",
      "sixty-nine",    "seventy",       "seventy-one",  "seventy-two",
      "seventy-three", "seventy-four",  "seventy-five", "seventy-six",
      "seventy-seven", "seventy-eight", "seventy-nine", "eighty",
      "eighty-one",    "eighty-two",    "eighty-three", "eighty-four",
      "eighty-five",   "eighty-six",    "eighty-seven", "eighty-eight",
      "eighty-nine",   "ninety",        "ninety-one",   "ninety-two",
      "ninety-three",  "ninety-four",   "ninety-five",  "ninety-six",
      "ninety-seven",  "ninety-eight",  "ninety-nine",  "hundred"};

  int count = 0;
  int letters = 0;

  // couunt first 99
  for (int i = 0; i < 99; i++) {
    letters = count_letters(number_words[i]);
    count += letters;
    printf("%s: %d\n", number_words[i], count);
  }

  // count 100 to 999
  for (int i = 0; i < 9; i++) {
    letters = count_letters(number_words[i]) + count_letters(number_words[99]);
    count += letters;
    printf("%s %s: %d\n", number_words[i], number_words[99], count);
    for (int j = 0; j < 99; j++) {
      letters = count_letters(number_words[i]) +
                count_letters(number_words[99]) + count_letters("and") +
                count_letters(number_words[j]);
      count += letters;
      printf("%s %s %s %s: %d\n", number_words[i], number_words[99], "and",
             number_words[j], count);
    }
  }
  letters = count_letters("one thousand");
  count += letters;
  printf("one thousand: %d\n", count);
  printf("%d\n", count);
  return 0;
}
