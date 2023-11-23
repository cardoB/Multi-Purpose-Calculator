//
//  User Input Functions.cpp
//  Menu Program
//
//  Created by Riccardo Belletta on 11/22/23.
//

#include "User Input Functions.h"
#include <iostream>
#include "Generic Functions.h"
#include "Constants.h"
using namespace std;


int get_input()
{
    int n;
    cout << "\nSelection: ";
    cin >> n;
    while (std::cin.fail() || n > NUM_OF_ITEMS || n < 0) {
            std::cout << "Invalid input. Please enter an integer between 0 and " << NUM_OF_ITEMS << ": ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cin >> n; // Try again
        }
    
    return n;
}

char getYesNo()
{
    char choice;

    while (!(std::cin >> choice) || (std::toupper(choice) != 'Y' && std::toupper(choice) != 'N')) {
        std::cout << "Invalid input. Please enter 'y' or 'n': ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cin >> choice; // Try again
    }
    return choice;
}

// gets an integer from user input
int getInteger()
{
    int n;
    cin >> n;
    while (std::cin.fail() || floor(n) != ceil(n)) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cin >> n; // Try again
        }
    
    return n;
    
}

// gets an integer from user input
int getInteger(int n, int m)
{
    int k;
    cin >> k;
    while (std::cin.fail() || floor(k) != ceil(k) || k < n || k > m) {
            std::cout << "Invalid input. Please enter an integer between " << n << " and " << m << ": ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cin >> n; // Try again
        }
    
    return k;
}

// gets a positive integer
int getPositiveInt()
{
    int n;
    cin >> n;
    while (std::cin.fail() || floor(n) != ceil(n) || n <= 0) {
            std::cout << "Invalid input. Please enter a positive integer: ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cin >> n; // Try again
        }
    return n;
}

// gets a real number from user input
double getReal()
{
    double n;

    while (!(std::cin >> n)) {
        // Input is not a numeric value
        std::cout << "Invalid input. Please enter a numeric value: ";
        std::cin.clear();  // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
    }
    return n;
    
}

// gets a real number from user input
double getPositiveReal()
{
    double n;

    while (!(std::cin >> n) || n <= 0) {
        // Input is not a numeric value
        std::cout << "Invalid input. Please enter a positive numeric value: ";
        std::cin.clear();  // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
    }
    return n;
}




