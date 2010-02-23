////////////////////////////////////////////////////////////////////////////////
// Lemon Example One: A Simple Factorial Function
//
// Time-stamp: <Last modified 2010-02-23 02:58:43 by Eric Scrivner>
//
// Description:
//   Provides a set of unit-tests using Lemon for a simple factorial function.
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

int main(int argc, char* argv[]) {
	// Setup lemon for 5 tests
	Lemon lemon(5);

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

	// Finish testing and display statistics
	lemon.end();

	return 0;
}
