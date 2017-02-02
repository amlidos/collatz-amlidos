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
  int m;
  int count = 1;
  int max = 1;
  int ret = 0;

  int metaCache[] = {
      1,       2,       3,      6,      7,      9,      18,     19,     25,
      27,      54,      55,     73,     97,     129,    171,    231,    235,
      313,     327,     649,    654,    655,    667,    703,    871,    1161,
      2223,    2322,    2323,   2463,   2919,   3711,   6171,   10971,  13255,
      17647,   17673,   23529,  26623,  34239,  35497,  35655,  52527,  77031,
      106239,  142587,  156159, 216367, 230631, 410011, 511935, 910107, 1676703,
      3030267, 3974407, 4484223};
  if (n < 5000000) {                  //references the meta cache in order to save ops when the number is less than 5,000,000 as it is already
    for (int i = 0; i < n - 1; ++i) { //calculated beforehand
      if (n >= metaCache[i] && n < metaCache[i + 1])
        return metaCache[i];
    }
  }

  int *lazyCache = new int[n]; //the lazy cache I've made is populated with -1s as sequence length !< 1
  for (int i = 0; i < n; ++i) {
    lazyCache[i] = -1;
  }
  lazyCache[0] = 1;

  for (int i = 1; i <= n; ++i) {
    m = i;
    while (m > 1) {
      if (m < n && lazyCache[m - 1] != -1) { //if the lazy cache gets a hit then it adds the sequence lengths
        count += lazyCache[m - 1] - 1;       //and sets m to 1 to avoid further evaluation
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
    lazyCache[i - 1] = count;       //saves value in cache
    if (count >= max) {
      max = count;                  //if a new max is found then set ret to be the current number being evaluated
      ret = i;
    }
    count = 1;  
  }
  assert(ret > 0);
  assert(ret <= n);
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
