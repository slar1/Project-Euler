#include "../include/time_date_utils.h"
#include <stdio.h>

int main() {
  // 30 days: sept (09), april (04), june (06), november (11)
  // 31 days: jan (01), march (03), may (05), july (07),
  // aug (08), oct (10), dec (12)
  // 28 days: feb (not leap year)
  // 29 days: feb (leap year)

  int start_year = 1900;
  int end_year = 2000;
  int days = 1;
  int sundays = 0;

  // go through each year
  for (int start = start_year; start <= end_year; start++) {
    // go through each month
    for (int month = 1; month <= 12; month++) {

      if (days % 7 == 0 && start != 1900) {
        sundays += 1;
      }

      // determine number of days in the month
      if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
          month == 10 || month == 12) {
        days += 31;

      } else if (month == 9 || month == 4 || month == 6 || month == 11) {
        days += 30;

      } else if (month == 2) {
        if (is_leap_year(start)) {
          days += 29;
        } else {
          days += 28;
        }
      }
    }
  }
  printf("%d\n", sundays);
  return 0;
}
