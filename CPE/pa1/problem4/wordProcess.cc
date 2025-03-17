#include "wordProcess.h"
#define ABS(x) ((x) >= 0 ? (x) : (-1) * (x))

std::string cpe::getMostPairsWord(std::string words[2500])
{
  //write your code here!
  int left = 0;
  int right = 0;
  int i = 0;
  int conNum[2500] = {0, };
  int maxPairs = 0;

  while(i < 2500)
  {
    left = 0;
    right = 0;
    int len = words[i].length();
    for(int j = 1; j < len; j++)
    {
      int prevIsPair = 0;
      int nextIsPair = 0;
      if(words[i][j-1] == words[i][j] || ABS(words[i][j-1] - words[i][j]) == 32)
        prevIsPair = 1;
      if(words[i][j+1] == words[i][j] || ABS(words[i][j+1] - words[i][j]) == 32)
        nextIsPair = 1;
      
      if(!prevIsPair)
        left = j;
      if(prevIsPair && !nextIsPair)
        right = j;
      if(left < right)
        conNum[i] += (right-left+1)/2;
      if(maxPairs < conNum[i])
        maxPairs = conNum[i];
    }
    i++;
  }

  std::string res;
  for(int j = 0; j < 2500; j++)
  {
    if(maxPairs == conNum[j])
    {
      res += words[j];
      res += "\n";
    }
      
  }

  return res;
}
