#ifndef FIND_PRIMES_H
#define FIND_PRIMES_H

/**
 * @file find_primes.h
 * @brief Function declarations find_primes
 */

/**
 * @brief Computes prime numbers below given value
 * @param n The given value
 * @return Pointer to list of prime numbers
 */
unsigned long *find_primes(unsigned long n);

/**
 * @brief Counts the number of primes in an array of primes
 * @param Pointer to array of primes
 * #return Returns integer number of primes
 */
int prime_count(unsigned long *prime_array);

#endif
