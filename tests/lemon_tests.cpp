////////////////////////////////////////////////////////////////////////////////
// lemon
//
// Time-stamp: <Last modified 2010-03-04 21:34:22 by Eric Scrivner>
//
// Description:
//   A test-suite for lemon using lemon itself (bootstrapping?)
////////////////////////////////////////////////////////////////////////////////
#include "../lemon.h"

////////////////////////////////////////////////////////////////////////////////
// Function: lemon_tests
//
// The lemon test suite.
int lemon_tests() {
	lemon::test<> lemon(16);
	lemon::test<lemon::output::nothing> t1(8);

	// Test 1: No failing tests to start off
	lemon.is(t1.num_failed(), 0, "initially zero tests have failed.");

	// Test 2 & 3: Test that ok works
	lemon.ok(t1.ok(true, ""), "ok returns true on true predicate.");
	lemon.not_ok(t1.ok(false, ""), "ok returns false on false predicate.");
	
	// Test 4: One failing test after failed ok
	lemon.is(t1.num_failed(), 1, "failure on ok increments number failed.");
	
	// Test 5 & 6: Test that not_o56k works
	lemon.not_ok(t1.not_ok(true, ""), "not_ok returns false on true predicate.");
	lemon.ok(t1.not_ok(false, ""), "not_ok returns true on false predicate.");
	
	// Test 7: One more failing test after failed not_ok
	lemon.is(t1.num_failed(), 2, "failure on not_ok increments number failed.");
	
	// Test 8 & 9: Test that is works
	lemon.ok(t1.is(1, 1, ""), "is returns true on identical inputs.");
	lemon.not_ok(t1.is(1, 2, ""), "is returns false on different inputs.");
	
	// Test 10: One more failing test after failed is
	lemon.is(t1.num_failed(), 3, "failure on is increments number failed.");
	
	// Test 11 & 12: Test that isnt works
	lemon.not_ok(t1.isnt(1, 1, ""), "isnt returns false on identical inputs.");
	lemon.ok(t1.isnt(1, 2, ""), "isnt returns true on different inputs.");
	
	// Test 13: One more faliing test after failed isnt
	lemon.is(t1.num_failed(), 4, "failure on isnt increments number failed.");

	// Test 14: Pass always returns true
	lemon.ok(t1.pass("passing test"), "pass always returns true");

	// Test 15 & 16: Fails always returns false and increments fail count
	lemon.not_ok(t1.fail("failing test"), "fail always returns false");
	lemon.is(t1.num_failed(), 5, "fail increments the number of failed tests.");

	// Return failure or success
	return lemon.done() ? 0 : 1;
}

int main(int argc, char* argv[]) {
	return lemon_tests();
}

