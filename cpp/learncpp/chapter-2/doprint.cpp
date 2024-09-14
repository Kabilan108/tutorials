#include <iostream>

// function header
void doPrint() {
  // function body 
  std::cout << "In doPrint()\n";
}

void printValue(int x) {
  std::cout << x << '\n';
}

// when this is called, the parameters are created as variables, with arguments copied into
// matchin params -> "pass by value"
// these are "value parameters"
int add(int x, int y) {
  return x + y;
}

int main() {
  std::cout << "starting main()\n";
  doPrint();  // interrupt main()N with a call to doPrint()
  printValue(5);
  printValue(add(2,3));
  std::cout << "ending main()\n";
}
