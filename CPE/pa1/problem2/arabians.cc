#include "arabians.h"

//implement this function
std::string cpe::reverseString(const std::string& target) {
  //write your code here!
  std::string reversed = target;

  int len = reversed.length();

  for(int i = 0; i < (len/2); i++)
  {
    char ch = reversed[i];
    reversed[i] = reversed[len-i-1];
    reversed[len-i-1] = ch;
  }
  return reversed;
}

