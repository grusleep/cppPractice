#include <iostream>
#include "guess.h"
using namespace std;
using namespace cpe;

int main()
{
  //write your code here
  //call genRandomNum function to generate a random number.
  //Use while loop here to start the game.
  //call guess function to check whether a user entered the correct target number.
  int n;
  int chance = 8;
  string N;
  genRandomNum();

  while(chance)
  {
    chance--;
    getline(cin, N);
    int isNum = 1;

    for(char ch : N)
    {
      if(ch < '0' || ch > '9')
      {
        cout << "Enter 0 to 99\n";
        isNum = 0;
        break;
      }
    }
    
    if(isNum)
    {
      n = stoi(N);
      if(chance > 0)
      {
        switch(guess(n))
        {
          case Result::CORRECT:
            cout << "You win\n";
            return 0;
            break;
          case Result::LARGE:
            cout << "More Larger\n";
            break;
          case Result::SMALL:
            cout << "More Smaller\n";
            break;
          case Result::FAIL:
            cout << "Enter 0 to 99\n";
            break;
        }
      }
      else if(chance == 0)
      {
        switch (guess(n))
        {
        case Result::CORRECT:
          cout << "You win\n";
          break;
        
        default:
          cout << "You Lose\n";
          break;
        }
      }
    }
  }
  return 0; 
}
