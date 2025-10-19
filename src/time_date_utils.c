#include "../include/time_date_utils.h"

int is_leap_year(int y) {
  if (y % 400 == 0) {
    return 1;
  } else if (y % 100 == 0) {
    return 0;
  } else if (y % 4 == 0) {
    return 1;
  } else {
    return 0;
  }
}
