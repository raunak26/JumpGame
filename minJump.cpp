//
// Created by Raunak Anand Sahu on 2019-04-28.
//

#include "minJump.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

void minjumps(std::vector<int> v, std::vector<int> s) {
  int i = 0;
  bool jumpgame = true;
  while (i != v.size() - 1)// checks if we have reached the end
  {
    s.push_back(i);
    if(v[i] == 0) // checks if a solution is possible
    {
      std::cout << "There is no solution to the given game."<< std::endl;
      jumpgame = false;
      break;
    }
    else if(i - v[i] <= 0)   // checks if the left jump can be made
    {
      i = i + v[i];
    }
    else if(std::find(s.begin(), s.end(), i - v[i]) != s.end() ) // checking if v already contains the number we will jump left to
    {
      i = i + v[i];
    }
    else if(v[i + v[i]] == v[i - v[i]] && std::find(s.begin(), s.end(), i + v[i]) == s.end())
    {
      i = i + v[i];
    }
    else if(v[i] + i + v[i + v[i]] == (v.size() - 1)) // checks if going right gives a direct way to go to the end
    {
      i = i + v[i];
      s.push_back(i);
      i = i + v[i];
    }
    else // base case where jumps left
    {
      i = i - v[i];
    }
  }
  s.push_back(i);

  if(jumpgame)
  {
    std::cout << "The solution is: {";
    for(int a = 0; a < (s.size() - 1 ); a++)
    {
      std::cout << s[a] << ',';
    }
    std::cout << s[s.size() - 1] ;
    std::cout << "}";
  }
}

