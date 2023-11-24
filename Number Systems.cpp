//
//  Number Systems.cpp
//  Menu Program
//
//  Created by Riccardo Belletta on 11/23/23.
//

#include "Number Systems.hpp"


#include <iostream>
#include <string>
#include "User Input Functions.h"
#include "Visuals.h"
#include "Constants.h"
#include <unistd.h>

using namespace std;

const int MAXSIZE = 500;

void NumberSystemProcessing()
{
    newLine();
    
    cout << padToLine("Base n number conversion\n");
    lineDivisor();
    
    char again = 'y';
    
    while (again == 'y')
    {
        int n, b;
        
        cout << "\nEnter a positive integer: ";
        n = getPositiveInt();
        
        cout << "Enter a positive conversion base: ";
        b = getInteger(2, 36);
        
        
        int q = n, k = 0;
        int a[MAXSIZE];
        
        q = n;
        
        while (q != 0)
        {
            int digit = q % b;
            a[k] = (digit);
            q = q / b;
            k++;
        }
        
        dotsDivisorln(DOTS);
        cout << n << " = ";
        
        for(int i = k - 1; i >= 0; i--)
        {
            if (a[i] < 10)
            {
                cout << a[i];
            }
            else if (a[i] >= 10 && a[i] <= 36)
            {
                cout << (char)(a[i] + 55);
            }
            else
            {
                cout << "-";
            }
        }
        cout << " base " << b << "\n";
        
        dotsDivisorln(DOTS);
        usleep(PAUSE);
        
        if (b > 10)
        {
            char c;
            cout << "Enter 'y' to see a table of values: ";
            cin >> c;
            if (c == 'y' || c == 'Y')
            {
                cout << "\n\n===================\n Characters Table:\nDecimal = base, for base > 10\n";
                for (int i = 0; i <= 9; i++)
                {
                    cout << i << " = " << i << endl;
                }
                for (int i = 10; i <= 35; i++)
                {
                    cout << i << " = " << (char)(i + 55) << endl;
                }
                cout << "- = undefined" << endl;
            }
        }

        againMessage();
        again = getYesNo();
    }
    
}
