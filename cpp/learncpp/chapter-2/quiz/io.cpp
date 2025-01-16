#include "io.h"

#include <iostream>

int readNumber() {
  std::cout << "Enter a number to add: ";
  int x {};
  std::cin >> x;
  return x;
}

void writeAnswer(int x) {
  std::cout << "answer = " << x << "\n";
}
