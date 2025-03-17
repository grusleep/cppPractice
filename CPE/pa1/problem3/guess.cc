#include "guess.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int randomNum = 0;

cpe::Result cpe::guess(int num) { 
  //write your code here!
  
  if(num < 0 || num > 99)
    return Result::FAIL;
  if(num < randomNum)
    return Result::LARGE;
  else if(num > randomNum)
    return Result::SMALL;
  else if(num == randomNum)
    return Result::CORRECT;
  return Result::CORRECT;
}
  //Implement genRandomNum function here
  //This generate random number and store it into randomNum variable
  //reference guess.h file for the function signature
void cpe::genRandomNum()
{
  srand(42);
  randomNum = rand()%100;
}
