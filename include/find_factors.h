#ifndef FIND_FACTORS_H
#define FIND_FACTORS_H

/**
 * @file find_factors.h
 * @brief Function(s) that finds the factors of a number.
 */

/**
 * @brief Compute list of factors for some number n using a quadratic sieve.
 * @param n The give number
 * @return Pointer to list of factors
 */
unsigned long *find_factors_qs(unsigned long n);

#endif
