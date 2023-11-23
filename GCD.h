//
//  GCD.h
//  Menu Program
//
//  Created by Riccardo Belletta on 11/22/23.
//

#ifndef GCD_h
#define GCD_h

#include <iostream>
using namespace std;

// Equation in the form: a = q(b) + r
struct Equation
{
    Equation(int a, int b, int z, int w)
    : a(a), b(b), q(z), r(w) { };
    
    void show(int a);
    bool check(); // returns true if equalit holds
    int a; // numerator
    int b; // denominator
    int q; // quotient
    int r; // remainder
    
    friend ostream& operator <<(ostream& stream, Equation& e);
};


// coefficient: c (integer); variable: x (integer)
struct Term
{
    Term(int x)
    : x(x), c(1) { };
    Term(int c, int x)
    : c(c), x(x) {};
    int x; // term x
    int c; // coefficient of x -> cx
    
    // Can only multiply like terms, for sake of problem
    // ex: (2)3 * (4)3 = (8)3
    friend Term operator *(const Term& t1, const Term& t2);
    
    // Multiply a term by a number: k*(c)d = (k*c)d
    friend Term operator *(int k, const Term& t);
    
    // adds two terms: ck + dk = (c+d)k, for integers c, k, d
    // ex: (2)3 + (4)3 = (6)3
    friend Term operator +(const Term& t1, const Term& t2);

    // outputs a term: ck -> (2)3
    friend ostream& operator <<(ostream& stream, Term& t);


};


// 4 terms equation: (c1)c2 + (c3)c4 + (c5)c6
struct Equation3;

//inverse of a mod m
int inverse(int a, int m);
// greatest common divisor
double gcd(int a, int b);
// Returns true if a is congruent to d (mod m)
bool isCongruent(int a, int d, int m);

void gcdProcessing();

//
#endif /* GCD_h */
