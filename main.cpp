#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "minJump.h"

int main(int argc, char** argv){
  if(argc < 2){
    std::cout << "There is no solution to the given game." << std::endl;
  }
  else{
    std::vector<int>problem(argc-1); //argument vector
    for (int i = 1; i < argc; ++i){
      problem[i-1] = std::stoi(argv[i]); // convert string arguments to integer
                                          // add them to 'problem' vector
    }

    std::vector<int>solution;//solution vector
    minjumps(problem, solution);

  }
  return 0;
}
