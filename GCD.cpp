//
//  GCD.cpp
//  Menu Program
//
//  Created by Riccardo Belletta on 11/22/23.
//

#include "GCD.h"
#include "User Input Functions.h"
#include "Visuals.h"
#include "Constants.h"
#include <iostream>
using namespace std;

ostream& operator <<(ostream& stream, Equation& e)
{
    stream << "a = " << e.a << "\nq = " << e.q << "\nb = " << e.b << "\nr = " << e.r << endl;
    return stream;
}

// outputs a term: ck -> (2)3
ostream& operator <<(ostream& stream, Term& t)
{
    stream << "(" << t.c << ")" << t.x;
    return stream;
}

// adds two terms: ck + dk = (c+d)k, for integers c, k, d
// ex: (2)3 + (4)3 = (6)3
Term operator +(const Term& t1, const Term& t2)
{
    if (t1.x != t2.x)
    {
        cout << "Can only add like-terms.\n";
        exit(1);
    }
    else
    {
        Term added(t1.x);
        added.c = t1.c + t2.c;
        return added;
    }
};

// Multiply a term by a number: k*(c)d = (k*c)d
Term operator *(int k, const Term& t)
{
    return Term(k * t.c, t.x);
}

// Can only multiply like terms, for sake of problem
// ex: (2)3 * (4)3 = (8)3
Term operator *(const Term& t1, const Term& t2)
{
    if (t1.x != t2.x)
    {
        cout << "Can only multiply like-terms.\n";
        exit(2);
    }
    else
    {
        return Term((t1.c * t2.c),(t1.x));
    }
}


bool Equation::check()
{
    return (a == q * b + r);
}


int inverse(int a, int m)
{
    if (gcd(a, m) != 1)
    {
        cout << a << " and " << m << " are not relatively prime.\n";
        return 0;
    }
    for (int i = 0; i <= m; i++)
    {
        if ((a * i) % m == 1)
        {
            return i;
        }
    }
    return 0;
}

double gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b%a, a);
}

void Equation::show(int c)
{
    switch (c) {
        case 1:
            cout << a << " = " << q << "(" << b << ") + " << r;
            break;
            
        case 2:
            cout << r << " = " << a << " - (" << q << ")" << b;
        default:
            break;
    }
}

bool isCongruent(int a, int d, int m)
{
    if (a % m == d % m)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void gcdProcessing()
{
    newLine();
    cout << padToLine("Euclidean Algorithm\n");
    lineDivisor();
    
    char again = 'y';
    
    while (again == 'y')
    {
        vector<Equation> equations;

        cout << "gcd(a, b) = sa + tb \n\nEnter a: ";
        int a;
        a = getPositiveInt();

        cout << "Enter b: ";
        int b;
        b = getPositiveInt();

        // fill equations vector with every step of algo
        int remainder;
        do
        {
            equations.push_back(Equation(a, b, a/b, a%b));
            remainder = a % b;
            a = b;
            b = remainder;

        } while (remainder != 0);

        //  Displays steps of Euclidian Algo
        
        dotsDivisorln(DOTS);
        for (int i = 0; i < equations.size(); i++)
        {
            equations[i].show(1);
            cout << endl;
        }
        dotsDivisorln(DOTS);
        
        againMessage();
        again = getYesNo();
        newLine();
    }
}
