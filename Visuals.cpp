//
//  Visuals.cpp
//  Menu Program
//
//  Created by Riccardo Belletta on 11/22/23.
//

#include <iostream>
#include <unistd.h>
#include "Visuals.h"
#include "Constants.h"

using namespace std;

void menu()
{
    lineDivisor();    
    cout << padToLine("Menu\n");
    lineDivisor();
    
    cout << " 1. Show Menu\n"
         << " 2. Multiplication Table\n"
         << " 3. Power Table\n"
         << " 4. Prime Numbers\n"
         << " 5. Leap Year\n"
         << " 6. Conversions\n"
         << " 7. Polynomial Calculator\n"
         << " 8. GCD as a linear combination\n"
         << " 9. Fibonacci Sequence time comparison\n"
         << "10. Decimal to Base n\n"
         << "0. Quit\n";
}

void lineDivisor()
{
    for (int i = 0; i < LINE_LENGTH; i++)
    {
        cout << "-";
    }
    cout << endl;
}


void dotsDivisor()
{
    cout << ".";
}

void dotsDivisor(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ".";
    }
}

void dotsDivisorln()
{
    cout << ".\n";
}

void dotsDivisorln(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ".";
    }
    cout << endl;
}

void tab()
{
    cout << " ";
}

void tab(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " ";
    }
}

void tabln()
{
    cout << " \n";
}

void tabln(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " ";
    }
    cout << endl;
}

void newLine()
{
    cout << "\n";
}

void newLine(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
    }
}

void againMessage()
{
    cout << "\nAgain (y/n)? ";
}

void backToMainMenu()
{
    newLine(2);
    tab(6);
    cout << "Back to main Menu...";
    newLine(2);
    usleep(PAUSE);
}

void printSmileyFace() {
    std::cout << "\n     #####  " << std::endl;
    std::cout << "    #######  " << std::endl;
    std::cout << "  #         # " << std::endl;
    std::cout << "  #  O   O  #" << std::endl;
    std::cout << "   #   ^   #" << std::endl;
    std::cout << "    #  ~  # " << std::endl;
    std::cout << "      ###  " << std::endl;
//    usleep(PAUSE / 2);
}

void byebye()
{
    printSmileyFace();
    cout << "\n\n    Bye Bye \n\n";
//    usleep(PAUSE / 2);
    
}

string padToLine(string s)
{
    unsigned long numberOfSpaces = (LINE_LENGTH - s.size() ) / 2;
    string paddedString = "";
    
    for (int i = 0; i < numberOfSpaces; i++)
    {
        paddedString += " ";
    }
    paddedString += s;
    
    return paddedString;
    
}
