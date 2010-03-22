////////////////////////////////////////////////////////////////////////////////
// all_tests.cpp - All tests for the lemon unit-testing framework
//
// Time-stamp: <Last modified 2010-03-22 16:41:49 by Eric Scrivner>
//
// Description:
//   A test-suite for lemon using lemon itself
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

int lemon_tests() {
	lemon::test<> lemon(19);

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

	lemon.is(t1.num_skipped(), 0, "number skipped is initially zero.");
	LEMON_SKIP(t1, "For testing purposes only") {
		t1.is(1, 2, "1 == 2");
		t1.is(2, 2, "2 == 2");
	}
	lemon.is(t1.num_skipped(), 2, "number skipped is correct after skipping.");
	lemon.is(t1.num_failed(), 5, "skipping does not add failing tests.");

	return lemon.done() ? 0 : 1;
}

int main(int argc, char* argv[]) {
	return lemon_tests();
}

