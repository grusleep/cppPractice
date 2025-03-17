#include "arrayModify.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//implement these functions
void printArray(int *arr, int num){
  //write your code here!
  for(int i = 0; i < num; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
void arrayModify(int *arr, int num){
  //write your code here!
  for(int i = 0; i < num; i++)
  {
    if(*(arr+i)%2 == 1)
    {
      *(arr+i) *= 2;
    }
    else
    {
      *(arr+i) += 1;
    }
  }

  sort(arr, arr+10);
}

