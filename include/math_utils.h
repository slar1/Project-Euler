#ifndef MATH_UTILS_H
#define MATH_UTILS_H
#include <gmp.h>
/**
 * @file math_utils.h
 * @brief Various math functions
 */

/**
 * @brief Calculate the factorial of a number
 * @param unsligned long long n
 * @return unsigned long long n factorial (n!)
 */
unsigned long long factorial(int n);

/*
 * @brief Caclulates binomial coefficient
 * @param int n and k where n >= k >= 0
 * @return binomial coefficient
 */
unsigned long long binomial_coefficient(int n, int k);

/*
 * @brief Caclulates large factorials
 * @param mpz_t result and int n factorial limit
 * @return void
 */
void factorial_big(mpz_t result, int n);
#endif
