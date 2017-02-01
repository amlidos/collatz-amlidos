// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2017
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read_1) {
  istringstream r("10\n");
  const int n = collatz_read(r);
  ASSERT_EQ(10, n);
}

TEST(CollatzFixture, read_2) {
  istringstream r("1\n");
  const int n = collatz_read(r);
  ASSERT_EQ(1, n);
}

TEST(CollatzFixture, read_3) {
  istringstream r("100\n");
  const int n = collatz_read(r);
  ASSERT_EQ(100, n);
}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
  const int m = collatz_eval(10);
  ASSERT_EQ(9, m);
}

TEST(CollatzFixture, eval_2) {
  const int m = collatz_eval(15);
  ASSERT_EQ(9, m);
}

TEST(CollatzFixture, eval_3) {
  const int m = collatz_eval(20);
  ASSERT_EQ(19, m);
}

TEST(CollatzFixture, eval_4) {
  const int m = collatz_eval(1);
  ASSERT_EQ(1, m);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 10);
  ASSERT_EQ("10\n", w.str());
}

TEST(CollatzFixture, print_2) {
  ostringstream w;
  collatz_print(w, 1);
  ASSERT_EQ("1\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 100);
  ASSERT_EQ("100\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
  istringstream r("3\n10\n15\n20\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("9\n9\n19\n", w.str());
}

TEST(CollatzFixture, solve_2) {
  istringstream r("3\n1\n4\n7\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1\n3\n7\n", w.str());
}
