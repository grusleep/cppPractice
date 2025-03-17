#include <iostream>
#include <string>
#include "fraction.h"

using namespace std;

int main() {
	//write your code here
	string str;
	string d;
  double d2;
	cin >> str;
	cin >> d;  

  try
  {
    d2 = stod(d);
  }
  catch(const std::exception& e)
  {
    cout << "Incorrect Input\n";
    return 0;
  }
  

  try
  {
    Fraction frac1;
    Fraction frac2;

	  frac1 = frac1.str2Fraction(str);
    
    frac2 = frac2.double2Fraction(d2);

    frac1.print();
    frac2.print();
    frac1.sum(frac1).print();
    frac1.sum(d2).print();
    frac2.multiply(frac1).print();
    frac2.multiply(d2).print();
    cout << fixed;
    cout.precision(6);
    cout << frac1.toDouble() << endl;
    cout << frac2.toDouble() << endl;

  }
  catch (const std::exception& e)
  {
    cerr << e.what() << endl;
  }
	return 0;
}