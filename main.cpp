//
//  main.cpp
//  Menu Program
//
//  Created by Riccardo Belletta on 2/15/23.
//
#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <cstdlib>
#include "Constants.h"
#include "Generic Functions.h"
#include "User Input Functions.h"
#include "Visuals.h"
#include "Polynomial Processing.h"
#include "GCD.h"
#include "Fibonacci.hpp"
#include "Number Systems.hpp"

using namespace std;


int main()
{
    
    
    menu();
    int selection = get_input();
    while (selection != 0)
    {
        switch (selection)
        {
        case 1:
        {
            menu();
            selection = get_input();
            break;
        }
        case 2:
        {
            multiplication();
            menu();
            selection = get_input();
            break;
        }
        case 3:
        {
            power();
            menu();
            selection = get_input();
            break;
        }
        case 4:
        {
            primeNumbers();
            menu();
            selection = get_input();
            break;
        }
        case 5:
        {
            leap();
            menu();
            selection = get_input();
            break;
        }
        case 6:
        {
            converter();
            menu();
            selection = get_input();
            break;
        }
        case 7:
        {
            polynomialProcessing();
            menu();
            selection = get_input();
            break;
        }

        case 8:
        {
            gcdProcessing();
            menu();
            selection = get_input();
            break;
        }
        case 9:
        {
            fibonacciProcessing();
            menu();
            selection = get_input();
            break;
        }
        case 10:
        {
            NumberSystemProcessing();
            menu();
            selection = get_input();
            break;
        }

        default:
        {
            cout << "Invalid Option...\n";
            usleep(PAUSE);
            menu();
            selection = get_input();
            break;
        }
        }
    }

    byebye();

    return 0;
}
