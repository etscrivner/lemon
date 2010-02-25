////////////////////////////////////////////////////////////////////////////////
// lemon
// Author: Eric Scrivner
//
// Time-stamp: <Last modified 2010-02-25 14:05:00 by Eric Scrivner>
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
  Lemon (unsigned int num_planned_tests)
  : num_tests_(0),
    test_number_(0),
    num_skipped_(0),
    num_failed_(0)
  {
    std::cout << "1.." << num_planned_tests << std::endl;
  }
  
  //////////////////////////////////////////////////////////////////////////////
  // Function: done
  //
  // Signifies the end of the testing phase and prints the results.
  //
  // Returns true if all unskipped tests passed, false if there were failures.
  bool done () {
      // If any tests were skipped
    if (num_skipped_ > 0) {
      // Display information about the skipped tests
      std::cout << "# Looks like you planned " << num_tests_;
      std::cout << " but only ran " << (num_tests_ - num_skipped_) << ".\n";
    }
    
    // If any tests were failed
    if (num_failed_ > 0) {
      // Display test failure statistics
      std::cout << "# Looks like you failed " << num_failed_;
      std::cout << " of " << num_tests_ << " tests.\n";
      return false;
    } else {
      // Otherwise display success message
      std::cout << "# Looks like you passed all " << num_tests_ << " tests.\n";
      return true;
    }
  }
  
  //////////////////////////////////////////////////////////////////////////////
  // Function: diag
  //
  // Parameters:
  //    message - A string to be written out to the display
  //
  // Used to display diagnostic information which is not a unit test.
  void diag (const std::string& message) {
    std::cout << "# " << message << std::endl;
  }
  
  //////////////////////////////////////////////////////////////////////////////
  // Function: ok
  //
  // Parameters:
  //    passed - True indicates a passing condition, false indicates failure
  //    test_name - A short, descriptive name for this test
  //
  // Marks this test as passed if pass is true.  The test is marked as
  // failing otherwise.
  bool ok (bool passed, const std::string& test_name) {
    // Increment the number of tests run
    num_tests_++;
    
    // If this is a skip or todo message
    if (test_name[0] != '#') {
      // Not the safest thing, but append a dash to the front
      const_cast<std::string&>(test_name) = "- " + test_name;
    }
    
    // If the test was passed
    if (passed) {
      // Inform you that the test passed
      std::cout << "ok " << num_tests_ << " " << test_name << "\n";
    } else {
      // Otherwise increment the number of failed tests
      num_failed_++;
      
      // Inform you that the test failed
      std::cout << "not ok " << num_tests_ << " " << test_name << "\n";
      diag("  Test failed, expected <true> but was <false>");
    }
  
    return passed;
  }
  
  //////////////////////////////////////////////////////////////////////////////
  // Function: not_ok
  //
  // Parameters:
  //    failed - False indicates a passing condition, true indicates failure
  //    test_name - A short, descriptive name for this test
  //
  // Marks this test as passed if the boolean parameter is false. The test is 
  // marked as failing otherwise.
  bool not_ok (bool failed, const std::string& test_name) {
    return ok(!failed, test_name);
  }

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
  template<typename T1, typename T2>
    bool is (const T1& this_one,
             const T2& that_one,
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
  template<typename T1, typename T2>
    bool isnt (const T1& this_one,
               const T2& that_one,
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
  // Marks the given test as trivially passing.
  bool pass (const std::string& test_name) {
    return ok(true, test_name);
  }

  //////////////////////////////////////////////////////////////////////////////
  // Function: fail
  //
  // Parameters:
  //    test_name - A short, descriptive name for this test
  //
  // Marks the given test as trivially failing.
  bool fail (const std::string& test_name) {
    return ok(false, test_name);
  }

  //////////////////////////////////////////////////////////////////////////////
  // Function: skip
  //
  // Parameters:
  //    reason - The reason for skipping this test
  //    num_to_skip - The number of tests to skip
  //
  // Skips the given number of tests adding them to the skip count.
  void skip (const std::string& reason, unsigned int num_to_skip) {
    num_skipped_ += num_to_skip;
  
    for (unsigned int i = 0; i < num_to_skip; i++) {
      pass("# SKIP " + reason);
    }	
  }

  //////////////////////////////////////////////////////////////////////////////
  // Function: todo
  //
  // Parameters:
  //    what - What needs to be done
  //
  // Prints a message indicating what is left to be done
  void todo (const std::string& what) {
    num_skipped_++;
    pass("# TODO " + what);
  }
private:
  unsigned int num_tests_; // The total number of tests to be executed
  unsigned int test_number_; // The number of the current test
  unsigned int num_skipped_; // The number of tests marked as skipped
  unsigned int num_failed_; // The number of tests marked as failing
};

#endif // LEMON_H__
