//
//  Generic Functions.cpp
//  Menu Program
//
//  Created by Riccardo Belletta on 11/22/23.
//

#include "Generic Functions.h"
#include <iostream>
#include <unistd.h>
#include <iomanip>
#include "User Input Functions.h"
#include "Constants.h"
#include "Visuals.h"

using namespace std;

void multiplication()
{
    double mult;
    int n;
    cout << "\n";
    tab(11);
    cout << "Multiplication Table\n";
    lineDivisor();
         

    char repeat = 'y';
    
    while (repeat == 'y')
    {
        cout << "Enter the number to be multiplied: ";
        mult = getReal();

        if (mult > 10000)
        {
            cout << "That number is a little too large" << endl;
        }

        cout << "Enter the number of multiples: ";
        n = getPositiveInt();
        if (n > 1000)
        {
            cout << "Can't do that much!" << endl;
        }
        if (n != 0)
        {

            int i;
            if (mult == 1)
            {
                cout << ".....\n";
                for (i = 1; i <= n; i++)
                {
                    cout << 1;
                    if (i < n)
                    {
                        cout << ", ";
                    }
                    else
                    {
                        cout << endl
                             << ".....\n";
                        usleep(PAUSE);
                    }
                }
            }
            else if (mult > 1)
            {
                cout << ".....\n";
                for (i = 1; i <= n; i++)
                {
                    cout << i * mult;
                    if (i < n)
                    {
                        cout << ", ";
                    }
                    else
                    {
                        cout << endl
                             << ".....\n";
                        usleep(PAUSE);
                    }
                }
            }
        }
        
        againMessage();
        repeat = getYesNo();
    }
    
    //
}

void power()
{
    double base;
    
    cout << endl;
    tab(16);
    cout << "Power Tables\n";
    lineDivisor();
    
    char again = 'y';
    
    while (again == 'y')
    {
        cout << "Enter the base: ";
        
        base = getReal();
        
        if (base > 50)
        {
            cout << "Can't do that much" << endl;
        }
        else if (base < 50)
        {
            int m;
            cout << "Enter the number of terms in the sequence: ";
            m = getPositiveInt();
            if (m > 3200)
            {
                cout << "Number too big" << endl;
            }
            else if (base < 50 && m < 3200)
            {

                unsigned long long result = 1;
                int exp;
                cout << ".....\n";
                for (exp = 1; exp <= m; exp++)
                {
                    cout << result * base;
                    if (exp < m)
                    {
                        result = result * base;
                        cout << ", ";
                    }
                    else
                    {
                        cout << endl
                             << ".....\n";
                        usleep(PAUSE);
                    }
                }
            }
        }
        
        againMessage();
        again = getYesNo();
    }
}

void primeNumbers()
{
    int selection;
    newLine();
    
    
    tab(15);
    cout << "Prime Numbers\n";
    lineDivisor();
    
    cout << "Choose an option\n"
         << "1. Prime numbers from 3 to N\n"
         << "2. Prime check\n"
         << "0. Exit\n";
    selection = get_input();

    switch (selection)
    {
    case 0:
    {
        backToMainMenu();
        break;
    }
    case 1:
    {
        int a = 3;
        int b;
        tab(9);
        cout << "Prime Numbers from 3 to n\n";
        lineDivisor();
        
        char again = 'y';
        
        while (again == 'y')
        {
            cout << "Choose n: ";
            b = getPositiveInt();
            
            cout << ".....\n";
            for (int i = a; i <= b; i++)
            {
                int count = 0;
                for (int j = 2; j < i; j++)
                {
                    if (i % j == 0)
                    {
                        count++;
                    }
                }
                if (count == 0)
                {
                    cout << i << ", ";
                }
            }
            cout << endl
                 << ".....\n";
            usleep(PAUSE);
            
            againMessage();
            again = getYesNo();
        }
        
        break;
    }
    case 2:
    {
        int n;
        
        newLine();
        tab(13);
        cout << "Prime number check\n";
        lineDivisor();
        
        char again = 'y';
        
        while (again == 'y')
        {
            cout << "Enter an integer: ";
            n = getPositiveInt();
            int count = 0;
            for (int i = 2; i < n; i++)
            {
                if (n % i == 0)
                {
                    count++;
                }
                else
                {
                    continue;
                }
            }

            cout << ".....\n";
            if (count == 0)
            {
                cout << n << " is a prime number.\n"
                     << ".....\n";
                usleep(PAUSE);
            }
            else
            {
                cout << n << " is not a prime number.\n"
                     << ".....\n";
                usleep(PAUSE);
            }
            
            againMessage();
            again = getYesNo();
        }
        
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

void leap()
{
    int year;
    newLine();
    tab(16);
    cout << "Leap Year\n";
    lineDivisor();
    
    cout << "Enter the year: ";
    year = getPositiveInt();
    if (year > 0)
    {
        if (year % 4 == 0)
        {
            if (year % 100 == 0 && year % 400 != 0)
            {
                cout << ".....\n";
                cout << year << " is not a leap year\n";
                cout << ".....\n";
                usleep(PAUSE);
            }
            else if (year % 400 == 0)
            {
                cout << ".....\n"
                     << year << " is a leap year\n"
                     << ".....\n";
                usleep(PAUSE);
            }
            else if (year % 4 == 0)
            {
                cout << ".....\n"
                     << year << " is a leap year\n"
                     << ".....\n";
                usleep(PAUSE);
            }
        }
        else if (year < 0)
        {
            cout << ".....\n"
                 << year << " is a weird year\n"
                 << ".....\n";
            usleep(PAUSE);
        }
        else
        {
            cout << ".....\n"
                 << year << " is not a leap year\n"
                 << ".....\n";
            usleep(PAUSE);
        }
    }
}

void converter()
{
    int selection;
    // Menu
    {
        newLine();
        tab(15);
        cout << "Conversions\n";
        lineDivisor();
        
        cout << "Choose an option:\n"
             << "1. mi/h -> km/h\n"
             << "2. km/h -> mi/h\n"
             << "3. 16th notes -> Sextuplets\n"
             << "4. Sextuplets -> 16th\n"
             << "5. Temperature\n"
             << "6. Seconds -> h/m/s\n"
             << "0. Exit\n";
    }

    selection = get_input();

    switch (selection)
    {
    case 0:
    {
        backToMainMenu();
        break;
    }

    case 1:
    {
        double s;
        
        char again = 'y';
        
        while (again == 'y')
        {
            cout << "mi/h: ";
            s = getPositiveReal();
            dotsDivisorln(DOTS);
            cout << setprecision(4) << s << " mi/h = " << s * 1.609344 << " km/h\n" << endl;
            dotsDivisorln(DOTS);
            usleep(PAUSE);
            
            againMessage();
            again = getYesNo();
        }
        break;
    }

    case 2:
    {
        double s;
        
        char again = 'y';
        
        while (again == 'y')
        {
            cout << "km/h: ";
            
            s = getPositiveReal();
            dotsDivisorln(6);
            cout << setprecision(4) << s << " km/h = " << s * 0.6213711 << " mi/h\n";
            dotsDivisorln(6);
            
            usleep(PAUSE);
            
            againMessage();
            again = getYesNo();
        }
        break;
    }

    case 3:
    {
        double s;
        
        char again = 'y';
        
        while (again == 'y')
        {
            cout << "Enter bpm for 16th notes: ";
            s = getPositiveReal();
            dotsDivisorln(DOTS);
            cout << setprecision(6) << s * 1.3333333 << " bpm" << endl;
            dotsDivisorln(DOTS);
            
            usleep(PAUSE);
            
            againMessage();
            again = getYesNo();
        }
        break;
    }

    case 4:
    {
        double s;
        char again = 'y';
        
        while (again == 'y')
        {
            
            cout << "Enter bpm for 12th notes: ";
            s = getPositiveReal();
            dotsDivisorln(DOTS);
            cout << setprecision(6) << s * 0.75 << " bpm\n" << endl;
            dotsDivisorln(DOTS);
            
            usleep(PAUSE);
         
            againMessage();
            again = getYesNo();
        }
            
        break;
    }

    case 5:
    {
        double temperatureC, temperatureF;
        int selection;
        lineDivisor();
        cout << "1. Celsius -> Fahrenheit\n2. Fahrenheit -> Celsius\n";
        selection = get_input();
        if (selection == 1)
        {
            char again = 'y';
            
            while (again == 'y')
            {
                cout << "\nEnter temperature in Celsius: \n";
                temperatureC = getReal();
                
                dotsDivisorln(DOTS);
                cout << temperatureC << "ºC = " << temperatureC * 1.8 + 32 << "ºF\n";
                dotsDivisorln(DOTS);
            
                usleep(PAUSE * 2);
                
                againMessage();
                again = getYesNo();
            }
            break;
        }
        if (selection == 2)
        {
            
            char again = 'y';
            
            while (again == 'y')
            {
                cout << "\nEnter temperature in Fahrenheit: \n";
                temperatureF = getReal();
                
                dotsDivisorln(DOTS);
                cout << temperatureF << "ºF = " << (temperatureF - 32) * 0.5556 << "ºC\n";
                dotsDivisorln(DOTS);
            
                usleep(PAUSE);
                
                againMessage();
                again = getYesNo();
            }
            break;
        }
    }

    case 6:
    {
        int num;
        
        char again = 'y';
        
        while (again == 'y')
        {
            
            cout << "\nEnter seconds: ";
            num = getPositiveReal();

            int hour = num / 3600;
            int min = (num - (hour * 3600)) / 60;
            int sec = num - (hour * 3600) - (min * 60);

            if (hour < 10)
            {
                dotsDivisorln(DOTS + 3);
                cout << "0" << hour << ":";

                if (min < 10 && sec < 10)
                {
                    cout << "0" << min << ":"
                         << "0" << sec << "\n";
                    dotsDivisorln(DOTS + 3);
                    usleep(PAUSE);
                }
                if (min < 10 && sec > 9)
                {
                    cout << "0" << min << ":" << sec << "\n";
                    dotsDivisorln(DOTS + 3);
                    usleep(PAUSE);
                }
                if (min > 9 && sec < 10)
                {
                    cout << min << ":"
                         << "0" << sec << "\n";
                    dotsDivisorln(DOTS + 3);
                    usleep(PAUSE);
                }
                if (min > 9 && sec > 9)
                {
                    cout << min << ":" << sec << "\n";
                    dotsDivisorln(DOTS + 3);
                    usleep(PAUSE);
                }
            }
            else if (hour > 10)
            {
                dotsDivisorln(DOTS + 3);
                cout << hour << ":";
                if (min < 10 && sec < 10)
                {
                    cout << "0" << min << ":"
                         << "0" << sec << "\n";
                    dotsDivisorln(DOTS + 3);
                    usleep(PAUSE);
                }
                if (min < 10 && sec > 9)
                {
                    cout << "0" << min << ":" << sec << "\n";
                    dotsDivisorln(DOTS + 3);
                    usleep(PAUSE);
                }
                if (min > 9 && sec < 10)
                {
                    cout << min << ":"
                         << "0" << sec << "\n";
                    dotsDivisorln(DOTS + 3);
                    usleep(PAUSE);
                }
                if (min > 9 && sec > 9)
                {
                    cout << min << ":" << sec << "\n";
                    dotsDivisorln(DOTS + 3);
                    usleep(PAUSE);
                }
            }
            
            againMessage();
            again = getYesNo();
            
        }
        
        break;
    }

    default:
    {
        cout << "Invalid Entry...\n";
        usleep(PAUSE);
        break;
    }
    }
}

