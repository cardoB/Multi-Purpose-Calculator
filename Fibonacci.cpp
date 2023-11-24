//
//  Fibonacci.cpp
//  Menu Program
//
//  Created by Riccardo Belletta on 11/23/23.
//

#include "Fibonacci.hpp"
#include "Visuals.h"
#include "User Input Functions.h"
#include <iostream>
#include <ctime>
#include "Constants.h"

using namespace std;

long fiboR(int n);
unsigned long long fiboI(int n);


void fibonacciProcessing()
{
    int n;
    newLine();
    cout << padToLine("Fibonacci algorithm: time complexity analysis\n");
    lineDivisor();
    cout << "Enter the term you are looking for: ";
    n = getPositiveInt();
       
    do
    {
        dotsDivisorln(DOTS);
        cout << "Term found iteratively: ";
        double t3 = clock(); // t1 = time taken to get to line 33
        cout << fiboI(n);
        double t4 = clock(); // t2 = time taken to get to line 35
        
        cout << "\nTerm found recursively: ";
        double t1 = clock(); // t1 = time taken to get to line 28, as 1/1000000 seconds
        cout << fiboR(n);
        double t2 = clock(); // t2 = time taken to get to line 30
        newLine();

        
        
        
        // time taken by function calls
        double timeRecursive = t2 - t1; // time it took to evaluate fiboR
        double timeIterative = t4 - t3; // time it took to evaluate fiboI
        
        // time it took for each:
        dotsDivisorln(DOTS);
        cout << "Time taken iteratively: " << timeIterative / 1000000 << " seconds"
        << "\nTime taken recursively: " << timeRecursive / 1000000 << " seconds";
        newLine();
        dotsDivisorln(DOTS);
        
        cout << "\nEnter another term (enter -1 to exit): ";
        cin >> n;
    
    } while (n > 0);

}


long fiboR(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fiboR(n - 1) + fiboR(n - 2));
}

unsigned long long fiboI(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        unsigned long long z = 0;
        unsigned long long x = 0;
        unsigned long long y = 1;
        for (int i = 1; i < n; i++)
        {
            z = x + y;
            x = y;
            y = z;
        }
        return y;
    }
}
