#include <iostream>

int getValue() {
  std::cout << "enter integer: ";
  int input{};
  std::cin >> input;

  return input;
}

int main() {
  int num { getValue() };

  std::cout << num << " x 2 = " << num *  2 << "\n";

  // value returned is a status/exit/return code
  // non-zero values = failute
  // C++ standard only defines 3 codes: 0 = EXIT_SUCCESS, EXIT_FAILURE
  // EXIT_SUCCESS and EXIT_FAILURE are preprocessor macros from <cstdlib>
  //
  //Preprocessor macros are directives processed before actual compilation. They're defined using #define. Macros can be constants, function-like, or more complex. They're replaced with their defined values or code during preprocessing.
  return 0;
}
