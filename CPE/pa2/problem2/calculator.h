#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator{
  //Write class definition here
  public:
    Calculator() {}
    void addition(int, int);
    void addition(double, double);

    void subtraction(int, int);
    void subtraction(double, double);

    void multiplication(int, int);
    void multiplication(double, double);

    void division(int, int);
    void division(double, double);

    void remainder(int, int);
    void remainder(double, double);

    void exponentiation(int, int);
    void exponentiation(double, double);
};

#endif
