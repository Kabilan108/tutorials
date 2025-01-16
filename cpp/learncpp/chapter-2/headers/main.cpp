// include order:
//   - parited header file
//   - headers from this project
//   - headers from 3rd party libs
//   - standard lib headers

#include "add.h"
#include "sub.h"

#include <iostream>

int main() {
  std::cout << "3 + 4 = " << add(3, 4) << '\n';
  std::cout << "3 - 4 = " << sub(3, 4) << '\n';
}

// run `g++ main.cpp add.cpp sub.cpp -o program` to compile
