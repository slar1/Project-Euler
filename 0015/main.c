#include "../include/math_utils.h"
#include <gmp.h>
#include <stdio.h>

int main() {
  // Starting in the top left corner of a grid, and only being able to move to
  // the right and down, there are exactly 6 routes to the bottom right corner.
  // How many such routes are there through a 20x20 grid?
  //
  // On a 20x20 grid there are only 20 rights that can be made, and 20 downs,
  // and 40 moves must be made.
  // The problem is about how many different combinations of right and down you
  // can make.
  // In the 2x2 grid example, 4 moves must be made, with 6 possible
  // combinations. this is the same as the number of possible combinations of 4
  // bits except 4 bits has 16 combinations the difference is for each bit
  // there's the possibility that it can be a 1 or 0. In this situation the down
  // or right is possible only if they haven't been done too many times. After
  // reading about lattice paths: https://en.wikipedia.org/wiki/Lattice_path the
  // number of lattice paths from (0,0) to (n,k) is equal to the binomial
  // coefficient.

  unsigned long n = 40;
  unsigned long k = 20;

  mpz_t bi_coef;
  mpz_init(bi_coef);
  mpz_bin_uiui(bi_coef, n, k);

  gmp_printf("%Zd\n", bi_coef);
  mpz_clear(bi_coef);

  return 0;
}
