#ifndef FIND_FACTORS_H
#define FIND_FACTORS_H

/**
 * @file find_factors.h
 * @brief Function(s) that finds the factors of a number.
 */

/**
 * @brief struct for quadratice sieve to return factors
 */
typedef struct {
  unsigned long p;
  unsigned long q;
} p_q;

/**
 * @brief Quadratic sieve finds two non trivial factors for some number n
 * @param n
 * @return p and q, two non trivial factors
 */
// p_q quadratic_sieve(unsigned long n);

/**
 * @brief Simple iteration to find two factors for n. Good for less than 20
 * digits.
 * @param n
 * @return p and q, two non trivial factors.
 */
p_q small_n_factors(unsigned long n);

/**
 * @brief Determines if a number is a perfect square
 * @param n
 * @return 1 if true, 0 if false
 */
int is_perfect_square(unsigned long n);

/**
 * @brief Compute list of factors for some number n using a quadratic sieve.
 * @param n The give number
 * @return Pointer to list of factors
 */
// unsigned long *find_factors_qs(unsigned long n);

/**
 * @brief Computes greatest common denominator between two
 * unsigned longs using the classical method
 * @param m, n
 * @return unsigend long. Greatest common denominator
 */
unsigned long euclidean_gcd(unsigned long a, unsigned long b);

/**
 * @brief Calculates list of factors for a number n. Simple brute force
 * @param n
 * @return unsigend long List of factors
 */
unsigned long *find_factors_simple(unsigned long n);

#endif
