#include <iostream>
#include "display.h"
#include "arabians.h"

using namespace std;

int main(){
  string s;
  
  getline(cin, s);

  s = cpe::reverseString(s);
  cpe::customPrint(s);
  //write your code here!
  //receive user input and store it into s varaible.
  //call reverseString function to reverse string
  //call customPrint function to print string
  return 0;
}
