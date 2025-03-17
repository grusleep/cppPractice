#include "calculator.h"
#include <iostream>

using namespace std;

//Implement Member Functions

void Calculator::addition(int a, int b)
{
    int res = a + b;
    cout << "Answer: " << res << endl;
}

void Calculator::addition(double a, double b)
{
    double res = a + b;
    string s = to_string(res);
    cout << "Answer: " << s << endl;
}

/*===========================================================*/

void Calculator::subtraction(int a, int b)
{
    int res = a - b;
    cout << "Answer: " << res << endl;
}

void Calculator::subtraction(double a, double b)
{
    double res = a - b;
    string s = to_string(res);
    cout << "Answer: " << s << endl;
}

/*=========================================================*/

void Calculator::multiplication(int a, int b)
{
    int res = a * b;
    cout << "Answer: " << res << endl;
}

void Calculator::multiplication(double a, double b)
{
    double res = a * b;
    string s = to_string(res);
    cout << "Answer: " << s << endl;
}

/*=========================================================*/

void Calculator::division(int a, int b)
{
    if (b == 0)
    {
        throw runtime_error("Operation disallowed");
    }
    int res = a / b;
    cout << "Answer: " << res << endl;
}

void Calculator::division(double a, double b)
{
    if (b == 0)
    {
        throw runtime_error("Operation disallowed");
    }
    double res = a / b;
    string s = to_string(res);
    cout << "Answer: " << s << endl;
}

/*=========================================================*/

void Calculator::remainder(int a, int b)
{
    if (b == 0)
    {
        throw runtime_error("Operation disallowed");
    }
    int res = a % b;
    cout << "Answer: " << res << endl;
}

void Calculator::remainder(double a, double b)
{
    if (b == 0)
    {
        throw runtime_error("Operation disallowed");
    }
    int res = (int)a % (int)b;
    cout << "Answer: " << res << endl;
}

/*=========================================================*/

void Calculator::exponentiation(int a, int b)
{
    int res = 1;
    for (int i = 1; i <= b; i++)
    {
        res *= a;
    }
    cout << "Answer: " << res << endl;
}

void Calculator::exponentiation(double a, double b)
{
    double res = 1;
    for (int i = 1; i <= b; i++)
    {
        res *= a;
    }
    string s = to_string(res);
    cout << "Answer: " << s << endl;
}

/*=========================================================*/
