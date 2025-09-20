/* 
 * prime_standard.c
 * Program to find and print all prime numbers up to a user-specified upper bound.
 *
 * Originally by Norman Matloff, UC Davis
 * Modified by Mark Ardis, RIT, 11/1/2006
 * Updated to follow RIT C coding standards
 */

#include <stdio.h>

#define ARRAY_SIZE (100)  // maximum size of prime array

/* 
 * check_prime
 * Purpose: Determine whether the given number is prime.
 * Input: number_to_check (int), primes[] (array storing prime flags)
 * Output: Updates primes[number_to_check] to 1 if prime, 0 otherwise
 */
void check_prime(int number_to_check, int primes[]) {
    int divisor;

    divisor = 2;
    // Only test divisors up to sqrt(number_to_check)
    while (divisor * divisor <= number_to_check) {
        if (primes[divisor] == 1) {
            if (number_to_check % divisor == 0) {
                primes[number_to_check] = 0;
                return;
            }
        }
        divisor++;
    }

    // If no divisors found, mark as prime
    primes[number_to_check] = 1;
}

int main() {
    int primes[ARRAY_SIZE];   // primes[i] will be 1 if i is prime, 0 otherwise
    int upper_bound;          // check all numbers up through this one for primeness
    int i;

    printf("Enter upper bound (<= %d):\n", ARRAY_SIZE - 1);
    scanf("%d", &upper_bound);

    if (upper_bound >= ARRAY_SIZE) {
        printf("Error: upper bound too large (max %d).\n", ARRAY_SIZE - 1);
        return 1;
    }

    // Initialize known primes
    primes[0] = 0;  // 0 is not prime
    primes[1] = 0;  // 1 is not prime
    primes[2] = 1;  // 2 is prime

    // Check odd numbers only (even numbers > 2 are not prime)
    for (i = 3; i <= upper_bound; i += 2) {
        check_prime(i, primes);
        if (primes[i]) {
            printf("%d is a prime\n", i);
        }
    }

    // Special case: print 2 since it was skipped in loop
    if (upper_bound >= 2) {
        printf("2 is a prime\n");
    }

    return 0;
}
