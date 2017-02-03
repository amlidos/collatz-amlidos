// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2017
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

int collatz_read(istream &r) {
  int n;
  r >> n;
  assert(n > 0);
  return n;
}

// ------------
// collatz_eval
// ------------

int collatz_eval(long long n) {
  assert(n > 0);

  long long metaCache[] = {
      1,       2,       3,       6,       7,       9,       18,      19,
      25,      27,      54,      55,      73,      97,      129,     171,
      231,     235,     313,     327,     649,     654,     655,     667,
      703,     871,     1161,    2223,    2322,    2323,    2463,    2919,
      3711,    6171,    10971,   13255,   17647,   17673,   23529,   26623,
      34239,   35497,   35655,   52527,   77031,   106239,  142587,  156159,
      216367,  230631,  410011,  511935,  626331,  837799,  1117065, 1126015,
      1501353, 1564063, 1723519, 2298025, 3064033, 3542887, 3732423};
  if (n < 3732423) {
    for (long long i = 0; i < (int)sizeof(metaCache) - 1; ++i) {
      if (n >= metaCache[i] && n < metaCache[i + 1])
        return metaCache[i];
    }
  }

  long long m;
  long long count = 1;
  long long max = 1;
  int ret = 0;

  long long *lazyCache = new long long[n];
  for (long long i = 0; i < n; ++i) {
    lazyCache[i] = -1;
  }
  lazyCache[0] = 1;

  for (long long i = 1; i <= n; ++i) {
    m = i;
    while (m > 1) {
      if (m < n && lazyCache[m - 1] != -1) {
        count += lazyCache[m - 1] - 1;
        m = 1;
      }
      if (m != 1) {
        if (m % 2 == 0)
          m /= 2;
        else {
          m = (3 * m + 1) / 2;
          ++count;
        }
        ++count;
      }
    }
    lazyCache[i - 1] = count;
    if (count >= max) {
      max = count;
      ret = i;
    }
    count = 1;
  }
  assert(ret > 0);
  delete[] lazyCache;
  return ret;
}

// -------------
// collatz_print
// -------------

void collatz_print(ostream &w, int m) {
  assert(m > 0);
  w << m << endl;
}

// -------------
// collatz_solve
// -------------

void collatz_solve(istream &r, ostream &w) {
  int t;
  r >> t;
  for (int _ = 0; _ != t; ++_) {
    const int n = collatz_read(r);
    const int m = collatz_eval(n);
    collatz_print(w, m);
  }
}
