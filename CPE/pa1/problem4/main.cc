#include <iostream>
#include "wordProcess.h"
#include <fstream>
using std::ifstream;
using std::cout;

int main()
{
  std::string a[2500];
  
  //Write your code here!
  //You should read file words.txt
  //call getMostParisWord function to find the most pairs of consecutive double letters
  ifstream fin;
  
  int i = 0;
  fin.open("words.txt");
  while(i < 2500)
  {
    getline(fin, a[i]);
    i++;
  }

  std::string str = cpe::getMostPairsWord(a);
  cout << str;

  fin.close();
}
