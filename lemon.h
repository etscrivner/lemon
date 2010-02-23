////////////////////////////////////////////////////////////////////////////////
// Lemon Unit Test Framework
// Author: Eric Scrivner
//
// Time-stamp: <Last modified 2010-02-23 02:21:13 by Eric Scrivner>
//
// Description:
//   A lightweight, minimal unit-testing framework based on Perl Test::More
////////////////////////////////////////////////////////////////////////////////
#ifndef LEMON_H__
#define LEMON_H__

#include <string>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// Class: Lemon
//
// Evaluates specific unit tests and displays result statistics
class Lemon
{
public:
  //////////////////////////////////////////////////////////////////////////////
  // Function: Lemon
  //
  // Parameters:
  //    num_planned_tests - The total number of tests you plan to execute
  //
  // This simply lets lemon know how many tests you're planning to run so that
  // it can properly output the diagnostic information and doesn't have to
  // count by hand (which can be tricky as one test can have many assertions).
  Lemon(unsigned int num_planned_tests);
  
  //////////////////////////////////////////////////////////////////////////////
  // Function: end
  //
  // Signifies the end of the testing phase and prints the results.
  void end();
  
  //////////////////////////////////////////////////////////////////////////////
  // Function: diag
  //
  // Parameters:
  //    message - A string to be written out to the display
  //
  // Used to display diagnostic information which is not a unit test.
  void diag(const std::string& message);
  
  //////////////////////////////////////////////////////////////////////////////
  // Function: ok
  //
  // Parameters:
  //    passed - True indicates a passing condition, false indicates failure
  //    test_name - A short, descriptive name for this test
  //
  // Marks this test as passed if pass is true.  The test is marked as
  // failing otherwise.
  bool ok(bool passed, const std::string& test_name);
  
  //////////////////////////////////////////////////////////////////////////////
  // Function: not_ok
  //
  // Parameters:
  //    failed - False indicates a passing condition, true indicates failure
  //    test_name - A short, descriptive name for this test
  //
  // Marks this test as passed if the boolean parameter is false. The test is 
  // marked as failing otherwise.
  bool not_ok(bool failed, const std::string& test_name);

  //////////////////////////////////////////////////////////////////////////////
  // Function: is
  //
  // Parameters:
  //    this_one - The left hand of the equality operator
  //    that_one - The right hand of the equality operator
  //    test_name - A short, descriptive name for this test
  //
  // Checks whether the two values are equal using the == operator. If
  // they are equal the test passes, otherwise it fails.
  template<typename type_t>
    bool is (const type_t& this_one,
             const type_t& that_one,
             const std::string& test_name)
  {
    bool passed = (this_one == that_one);
      
    ok(passed, test_name);
      
    if (!passed) {
      std::cout << "#         got: '" << this_one << "'\n";
      std::cout << "#    expected: '" << that_one << "'\n";
    }
      
    return passed;
  }

  //////////////////////////////////////////////////////////////////////////////
  // Function: isnt
  //
  // Parameters:
  //    this_one - The left hand of the inequality operator
  //    that_one - The right hand of the inequality operator
  //    test_name - A short, descriptive name for this test
  //
  // Checks whether the two values are equal using the != operator. If
  // they are not equal the test passes, otherwise the test fails.
  template<typename type_t>
    bool isnt (const type_t& this_one,
               const type_t& that_one,
               const std::string& test_name)
  {
    bool passed = (this_one != that_one);
      
    ok (passed, test_name);
      
    if (!passed) {
      std::cout << "#    '" << this_one << "'\n";
      std::cout << "#      !=\n";
      std::cout << "#    '" << that_one << "'\n";
    }
      
    return passed;
  }

  //////////////////////////////////////////////////////////////////////////////
  // Function: pass
  //
  // Parameters:
  //    test_name - A short, descriptive name for this test
  //
  // Marks the given test as passing without actually testing anything.
  bool pass (const std::string& test_name);

  //////////////////////////////////////////////////////////////////////////////
  // Function: fail
  //
  // Parameters:
  //    test_name - A short, descriptive name for this test
  //
  // Marks the given test as failing without actually testing anything.
  bool fail (const std::string& test_name);

  //////////////////////////////////////////////////////////////////////////////
  // Function: skip
  //
  // Parameters:
  //    reason - The reason for skipping this test
  //    num_to_skip - The number of tests to skip
  //
  // Skips the given number of tests adding them to the skip count.
  void skip (const std::string& reason, unsigned int num_to_skip);

  //////////////////////////////////////////////////////////////////////////////
  // Function: todo
  //
  // Parameters:
  //    what - What needs to be done
  //
  // Prints a message indicating what is left to be done
  void todo (const std::string& what);
private:
  unsigned int num_tests; // The total number of tests to be executed
  unsigned int test_number; // The number of the current test
  unsigned int num_skipped; // The number of tests marked as skipped
  unsigned int num_failed; // The number of tests marked as failing
};

#endif // LEMON_H__
