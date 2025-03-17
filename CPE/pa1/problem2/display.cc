#include "display.h"
#include <iostream>
using namespace std;

//implement this function
void cpe::customPrint(const std::string& s){
  //write your code here!
  int left = 0;
  int right = 0;

  string res = s;
  int len = res.length();

  for(int i = 1; i < len; i++)
  {
    if(res[i] >= '0' && res[i] <= '9')
    {
      if(res[i-1] < '0' || res[i-1] > '9')
        left = i;
      else if(res[i+1] < '0' || res[i+1] > '9')
        right = i;

      if(res[i+1] < '0' || res[i+1] > '9')
      {
        while(left < right)
        {
          char ch = res[left];
          res[left] = res[right];
          res[right] = ch;
          left++;
          right--;
        }
      }    
    }
  }

  cout << res;
}

