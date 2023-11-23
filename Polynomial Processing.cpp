//
//  Polynomial Processing.cpp
//  Menu Program
//
//  Created by Riccardo Belletta on 11/22/23.
//

#include "Polynomial Processing.h"
#include "Polynomial.h"
#include "Visuals.h"
#include "Constants.h"
#include "User Input Functions.h"
#include <unistd.h>
#include <iostream>
using namespace std;


void polynomialProcessing()
{
    welcomePolynomial();
    
    cout << "\t\t 1st function\n";
    Polynomial f = getPolynomial('x');
    
    cout << "\t\t 2nd function\n";
    Polynomial g = getPolynomial('x');
    
    int selection;
    do
    {
        lineDivisor();
        menuPolynomial();
        selection = getInteger(0, NUM_OF_POLYNOMIAL_ITEMS);
        
        if (selection != 0)
        {
            if (selection == 1)
            {
                dotsDivisorln(DOTS);
                cout << endl;
                f.display();
                cout << endl;
                g.display();
                newLine();
                dotsDivisorln(DOTS);
                usleep(PAUSE);
            }
            
            else if (selection == 2)
            {
                cout << "\nWhich polynomial are you trying to evaluate?\n\n1. first entry\n2. second entry\n3. Both\n\nSelect: ";
                int whichOne;
                whichOne = getInteger(1, 3);
                
                if (whichOne == 1)
                {
                    cout << "Enter the input value: ";
                    double x;
                    x = getReal();
                    
                    double result = f.evaluate(x);
                    dotsDivisorln(DOTS);
                    cout << endl << f.getName() << "(" << x << ") = " << result << "\n\n";
                    dotsDivisorln(DOTS);
                    usleep(PAUSE);
                }
                else if (whichOne == 2)
                {
                    cout << "Enter the input value: ";
                    double x;
                    x = getReal();
                
                    double result = g.evaluate(x);
                    dotsDivisorln(DOTS);
                    cout << endl << g.getName() << "(" << x << ") = " << result << "\n\n";
                    dotsDivisorln(DOTS);
                    usleep(PAUSE);
                }
                else if (whichOne == 3)
                {
                    cout << "Enter the input value: ";
                    double x;
                    x = getReal();
                
                    double resultG = g.evaluate(x);
                    double resultF = f.evaluate(x);
                    dotsDivisorln(DOTS);
                    cout << f.getName() << "(" << x << ") = " << resultF << endl;
                    cout << g.getName() << "(" << x << ") = " << resultG << "\n";
                    dotsDivisorln(DOTS);
                    usleep(PAUSE);
                }
            }
            
            else if (selection == 3)
            {
                Polynomial sum = f + g;
                dotsDivisorln(DOTS);
                cout << f << " + (" << g << ") = ";
                cout << sum << "\n";
                dotsDivisorln(DOTS);
                usleep(PAUSE);
            }
            
            else if (selection == 4)
            {
                Polynomial diff1 = f - g;
                Polynomial diff2 = g - f;
                
                cout << endl;
                dotsDivisorln(DOTS);
                
                cout << f << " - (" << g << ") = ";
                cout << diff1 << endl;
                
                cout << g << " - (" << f << ") = ";
                cout << diff2 << "\n";
                dotsDivisorln(DOTS);
                usleep(PAUSE);
                
            }
            
            else if (selection == 5)
            {
                Polynomial prod = f * g;
                dotsDivisorln(DOTS);
                cout << "(" << f << ")*(" << g << ") = " << prod << "\n\n";
                dotsDivisorln(DOTS);
                usleep(PAUSE);
            }
            
            else if (selection == 6)
            {
                Polynomial fPrime = f.derivative();
                dotsDivisorln(DOTS);
                
                cout << f.getName() << "'(x) = " << fPrime << endl;
                
                Polynomial gPrime = g.derivative();
                
                cout << g.getName() << "'(x) = " << gPrime << "\n";
                dotsDivisorln(DOTS);
                usleep(PAUSE);
            }
            
            else if (selection == 7)
            {
                cout << "Enter an input segment as two numbers: ";
                double x1, x2;
                x1 = getReal();
                
                x2 = getReal();
                
                dotsDivisorln(DOTS);
                
                
                cout << "The Average Rate of Change of " << f.getName() << " between " << x1 << " and " << x2 << " is " << f.ARC(x1, x2) << endl;
                
                cout << "The Average Rate of Change of " << g.getName() << " between " << x1 << " and " << x2 << " is " << g.ARC(x1, x2) << "\n";
                dotsDivisorln(DOTS);
                usleep(PAUSE);
            }
        }
    } while (selection > 0 && selection <= 6);

}
