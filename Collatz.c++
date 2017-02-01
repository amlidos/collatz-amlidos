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

int collatz_read (istream& r) {
    int n;
    r >> n;
    assert(n > 0);
    return n;}

// ------------
// collatz_eval
// ------------

int collatz_eval (long long n) {
    assert(n > 0);
    int m;
    int count = 1;
    int max = 1;
    int ret = 0;
   
    for(int i = 1; i <= n; ++i)
    {
        m = i;
        while(m > 1)
        {
            if(m % 2 == 0)
                m /= 2;
            else
                m = 3*m+1;
            ++count;
        }
        if(count >= max)
        {
            max = count;
            ret = i;
        }
        count = 1;
    }
    assert(ret > 0);
    assert(ret <= n);
    return ret;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int m) {
    assert(m > 0);
    w << m << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    int t;
    r >> t;
    for (int _ = 0; _ != t; ++_) {
        const int n = collatz_read(r);
        const int m = collatz_eval(n);
        collatz_print(w, m);}}
