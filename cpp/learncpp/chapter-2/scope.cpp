#include <iostream>

// forwared declaration
int add(int x, int y); // function declaration/prototype (pure declaration)

// variables destroyed in the opposite order of creation when functions exit

// local variables cannot be used before the point of definition 


// x is not in scope in this fn
void doSth() {
  std::cout << "hello\n";
}

int main() {
  // x not in scope yet
  int x{0}; // x enters scope here
  doSth();

  return 0;
}  // x goes out of scope (not all varsare destroyed when they go out of scope)

int add(int x, int y) // x and y are local vars (definition)
{
  int z{ x + y}; // z is local
  return z;
}
