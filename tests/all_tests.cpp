////////////////////////////////////////////////////////////////////////////////
// lemon
//
// Time-stamp: <Last modified 2010-03-22 13:34:23 by Eric Scrivner>
//
// Description:
//   A test-suite for lemon using lemon itself (bootstrapping?)
////////////////////////////////////////////////////////////////////////////////
#include "../lemon.h"

int lemon_tests() {
	lemon::test<> lemon(16);

	lemon::test<lemon::output::nothing> t1(8);
	lemon.is(t1.num_failed(), 0, "initially zero tests have failed.");

	lemon.ok(t1.ok(true, ""), "ok returns true on true predicate.");
	lemon.not_ok(t1.ok(false, ""), "ok returns false on false predicate.");
	lemon.is(t1.num_failed(), 1, "failure on ok increments number failed.");

	lemon.not_ok(t1.not_ok(true, ""), "not_ok returns false on true predicate.");
	lemon.ok(t1.not_ok(false, ""), "not_ok returns true on false predicate.");
	lemon.is(t1.num_failed(), 2, "failure on not_ok increments number failed.");

	lemon.ok(t1.is(1, 1, ""), "is returns true on identical inputs.");
	lemon.not_ok(t1.is(1, 2, ""), "is returns false on different inputs.");
	lemon.is(t1.num_failed(), 3, "failure on is increments number failed.");

	lemon.not_ok(t1.isnt(1, 1, ""), "isnt returns false on identical inputs.");
	lemon.ok(t1.isnt(1, 2, ""), "isnt returns true on different inputs.");
	lemon.is(t1.num_failed(), 4, "failure on isnt increments number failed.");

	lemon.ok(t1.pass("passing test"), "pass always returns true");
	lemon.not_ok(t1.fail("failing test"), "fail always returns false");
	lemon.is(t1.num_failed(), 5, "fail increments the number of failed tests.");

	return lemon.done() ? 0 : 1;
}

int main(int argc, char* argv[]) {
	return lemon_tests();
}

