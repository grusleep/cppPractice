#include <iostream>
#include <string>

#include "arrayModify.h"

using namespace std;

int main(){
  //write your code here!
  //you should call arrayModify function to modify array
  //you should call printArray function to print array
  int arr[10] = {0, };

  int notErr = 1;

  string str;
  getline(cin, str);
  
  int i = 0;
  int flag = 0;
  int len = str.length();

  
  for(char tem : str)
  {
    if(i == 10) break;
    if(tem != ' ')
    {
      flag++;
      if(flag == 2)
      {
        break;
      }
      arr[i] = tem - '0';
      i++;
    }
    else if(tem == ' ')
    {
      flag = 0;
    }
  }
  
  if(len != 19)
  {
    if(flag == 2) cout << "Number must be between 0~9\n";
    else cout << "Enter 10 numbers\n";
    notErr = 0;
  }

  if(notErr)
  {
    if(flag == 2) cout << "Number must be between 0~9\n";
    else
    {
      arrayModify(arr, 10);
      printArray(arr, 10);
    }
  }
  
  return 0;
}
