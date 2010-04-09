///////////////////////////////////////////////////////////////////////////////
// factorial_test.cpp - A simple factorial example
//
// Time-stamp: <Last modified 2010-04-09 00:44:48 by Eric Scrivner>
//
// Description:
//   Provides a set of unit-tests using Lemon for a simple factorial function.
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
///////////////////////////////////////////////////////////////////////////////
#include "../lemon.h"

///////////////////////////////////////////////////////////////////////////////
// Function: factorial
//
// Computes the factorial of the given number
int factorial(int n) {
  if (n <= 0) return 1;

  int result = 1;
  while (n > 1) {
    result *= n;
    --n;
  }

  return result;
}

int main(int argc, char* argv[]) {
  lemon::test<> lemon(4);

  lemon.is(factorial(0), 1, "0! = 1");
  lemon.is(factorial(3), 3 * 2 * 1, "3! = 3 * 2 * 1");
  lemon.is(factorial(-5), 1, "(-5)! = 1");
  lemon.is(factorial(5), 120, "5! = 120");

  return lemon.done() ? 0 : 1;
}
