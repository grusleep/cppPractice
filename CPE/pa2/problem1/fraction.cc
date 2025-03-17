#include "fraction.h"
#include <iostream>
#include <string>

using namespace std;

//Implement Member Functions
Fraction Fraction::sum(Fraction b)
{
    Fraction a = *this;

    if(a.toMixedNum() && a.D == 0)
    {
        a.D = 1;
    }
    if(b.toMixedNum() && b.D == 0)
    {
        b.D = 1;
    }

    a.N += b.N;

    // 통분
    a.NU *= b.D;
    b.NU *= a.D;
    a.D *= b.D;
    a.NU += b.NU;

    a.abbreviation();

    return a;
}

Fraction Fraction::sum(double b)
{
    Fraction b2;
    b2 = b2.double2Fraction(b);
    Fraction a = *this;
    a = a.sum(b2);
    return a;
}

Fraction Fraction::multiply(Fraction b)
{
    Fraction a = *this;

    if(a.toMixedNum() && a.D == 0)
    {
        a.D = 1;
    }
    if(b.toMixedNum() && b.D == 0)
    {
        b.D = 1;
    }

    //가분수로 바꾸기
    a.NU += (a.N * a.D);
    a.N = 0;
    b.NU += (b.N * b.D);
    b.N = 0;

    a.NU *= b.NU;
    a.D *= b.D;

    a.abbreviation();

    return a;
}

Fraction Fraction::multiply(double b)
{
    Fraction b2;
    b2 = b2.double2Fraction(b);
    Fraction a = *this;
    a = a.multiply(b2);
    return a;
}

void Fraction::abbreviation()
{
    if (NU == 0) return;

    int nu = NU;
    int d = D;
    while (nu != 0) {
        int temp = d % nu;
        d = nu;
        nu = temp;
    }
    int GCD = d;
    NU /= GCD;
    D /= GCD;

    if (D == 1)
    {
        N += NU;
        NU = 0;
    }

    // 가분수 처리
    if (NU > D && D != 0)
    {
        N += (NU / D);
        NU %= D;
    }
    return;
}

bool Fraction::toMixedNum()
{
    long long int nu = NU;
    long long int d = D;
    abbreviation();
    if(nu != NU || d != D) return true;
    return false;
}

void Fraction::print()
{
    abbreviation();
    int d = D;
    if (NU == 0) d = 0;
    cout << N << " and " << NU << "/" << d << endl;
}

double Fraction::toDouble()
{
    double d = 0;
    d += (double)N;
    d += (NU / (double)D);
    return d;
}

Fraction Fraction::str2Fraction(string str)
{
    Fraction res;

    /*=======================에러==========================*/
    int slash = 0;
    //숫자와 '/'로만 구성 확인
    for (char e : str)
    {
        if (e < '0' || e > '9')
        {
            if (e == '/')
            {
                slash++;
                continue;
            }
            throw runtime_error("Incorrect Input");
        }
    }
  
    //'/'가 2개인지 확인
    if (slash != 2) throw runtime_error("Incorrect Input");

    //'/'사이에 값이 존재하는지 확인
    int len = str.length() - 1;
    if (str[0] == '/')
        throw runtime_error("Incorrect Input");
    else if (str[len] == '/')
        throw runtime_error("Incorrect Input");
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '/' && str[i+1] == '/')
            {
                throw runtime_error("Incorrect Input");
            }
        }
    }
    
    //분모가 0인지 확인
    if (str[len-1] == '/' && str[len] == '0') throw runtime_error("Incorrect Input");

    /*=====================================================*/

    int i = 0;
    string token = "";
    while (str[i] != '/')
    {
        token += str[i];
        i++;
    }
    i++;
    res.N = stoi(token);
    token = "";

    while (str[i] != '/')
    {
        token += str[i];
        i++;
    }
    i++;
    res.NU = stoi(token);
    token = "";

    while (str[i] != '\0')
    {
        token += str[i];
        i++;
    }
    res.D = stoi(token);

    return res;
}

Fraction Fraction::double2Fraction(double val)
{
    Fraction res;

    string d = to_string(val);

    /*==============에러==================*/
    int dot = 0;
    for (char e : d)
    {
        if (e < '0' || e > '9')
        {
            if (e == '.' && dot == 0)
            {
                dot++;
                continue;
            }
            throw runtime_error("Incorrect Input");
        }
    }
    /*===================================*/

    res.N = val;
    string str = to_string(val);
    size_t dotPos = str.find('.');
    res.NU = stoi(str.substr(dotPos + 1));
    res.D = 1000000;

    return res;
}