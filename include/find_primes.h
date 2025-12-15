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
 * @brief Counts the number of elements in an array
 * @param Pointer to array.
 * #return Returns integer number of elements.
 */
// int array_count(unsigned long *prime_array);

/**
 * @brief Checks if number is prime.
 * @param A unsigned long n.
 * @return returns 1 for prime, and 0 for not prime.
 */
int isPrime(int n);

#endif
