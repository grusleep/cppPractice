#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include <iostream>
using namespace std;

class Fraction {
    //Write class definition here
public:
    Fraction(): N(0), NU(0), D(0) {}
    Fraction sum(Fraction);
    Fraction sum(double);
    Fraction multiply(Fraction);
    Fraction multiply(double);

    void abbreviation();
    bool toMixedNum();
    void print();
    double toDouble();
    Fraction str2Fraction(string);
    Fraction double2Fraction(double);

private:
    long long int N;
    long long int NU;
    long long int D;
};

#endif

