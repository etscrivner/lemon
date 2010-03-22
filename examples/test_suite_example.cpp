////////////////////////////////////////////////////////////////////////////////
// test_suite_example.cpp - A simple test suite using lemon
//
// Time-stamp: <Last modified 2010-03-22 16:46:48 by Eric Scrivner>
//
// Description:
//   Showcase one simple method for composing unit tests into suites
//
// Copyright (c) 2010 lemon team
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgment in the product documentation would be
// appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
// distribution.
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

bool factorial_test_suite() {
	lemon::test<> lemon(5);

	lemon.is(factorial(-5), 1, "(-5)! = 1");
	lemon.is(factorial(0), 1, "0! = 1");
	lemon.is(factorial(1), 1, "1! = 1");
	lemon.is(factorial(2), 2, "2! = 2");
	lemon.is(factorial(5), 120, "5! = 120");

	return lemon.done();
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

bool is_prime_test_suite() {
	lemon::test<> lemon(7);

	lemon.not_ok(is_prime(-5), "Negative numbers are not prime.");
	lemon.not_ok(is_prime(0), "Zero is non-prime.");
	lemon.not_ok(is_prime(1), "One is non-prime.");
	lemon.ok(is_prime(2), "Two is prime.");
	lemon.ok(is_prime(3), "Three is prime.");
	lemon.not_ok(is_prime(9), "Nine is non-prime.");
	lemon.ok(is_prime(113), "113 is prime.");

	return lemon.done();
}

int main(int argc, char* argv[]) {
	return (factorial_test_suite() && is_prime_test_suite()) ? 0 : 1;
}
