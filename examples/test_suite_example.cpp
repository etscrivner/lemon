////////////////////////////////////////////////////////////////////////////////
// Lemon Example Two: Test Suites
//
// Time-stamp: <Last modified 2010-02-27 16:02:54 by Eric Scrivner>
//
// Description:
//   Showcase one simple method for composing unit tests into suites
////////////////////////////////////////////////////////////////////////////////
#include "../lemon.h"

////////////////////////////////////////////////////////////////////////////////
// Function: factorial
//
// Computes the factorial of the given number
int factorial(int n) {
	if (n < 2) return 1;

	int result = 1;
	while (n > 1) {
		result *= n;
		--n;
	}

	return result;
}

void factorial_test_suite() {
	lemon::test<> lemon(5);

	// Test 1: The factorial function handles negative numbers as expected
	lemon.is(factorial(-5), 1, "(-5)! = 1");

	// Test 2: Factorial of zero is one
	lemon.is(factorial(0), 1, "0! = 1");

	// Test 3: Factorial of one is one
	lemon.is(factorial(1), 1, "1! = 1");

	// Test 4: Factorial of 2 is 2
	lemon.is(factorial(2), 2, "2! = 2");

	// Test 5: Factorial of 5 is 120
	lemon.is(factorial(5), 120, "5! = 120");

	lemon.done();
}

////////////////////////////////////////////////////////////////////////////////
// Function: is_prime
//
// Uses the Sieve of Eratosthenes to determine if the given number is prime.
bool is_prime(int n) {
	if (n < 2) return false;

	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

void is_prime_test_suite() {
	lemon::test<> lemon(7);

	// Test 1: Negative numbers are by definition non-prime
	lemon.not_ok(is_prime(-5), "Negative numbers are not prime.");

	// Test 2: Zero is non-prime
	lemon.not_ok(is_prime(0), "Zero is non-prime.");

	// Test 3: One is non-prime
	lemon.not_ok(is_prime(1), "One is non-prime.");

	// Test 4: Two is the first prime number
	lemon.ok(is_prime(2), "Two is prime.");

	// Test 5: Three is prime
	lemon.ok(is_prime(3), "Three is prime.");

	// Test 6: Nine is composite and thus non-prime
	lemon.not_ok(is_prime(9), "Nine is non-prime.");

	// Test 7: 113 is prime
	lemon.ok(is_prime(113), "113 is prime.");

	lemon.done();
}

int main(int argc, char* argv[]) {
	factorial_test_suite();
	is_prime_test_suite();
	return 0;
}
